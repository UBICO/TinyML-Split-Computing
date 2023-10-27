/* 
 * ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * OTHER LIBS
 * ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 */
#include <WiFi.h>
#include <PubSubClient.h>
#include <sys/time.h>
#include <UUID.h>
#include <ArduinoJson.h>

/* 
 * ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * NN Modles Layers
 * ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 */
#define MODEL_NUMBER "04"
#include "models/model_04_layer_0.h"
#include "models/model_04_layer_1.h"
#include "models/model_04_layer_2.h"
#include "models/model_04_layer_3.h"
#include "models/model_04_layer_4.h"
#include "models/model_04_layer_5.h"
#include "models/model_04_layer_6.h"
#include "models/model_04_layer_7.h"
String nn = MODEL_NUMBER;

/* 
* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
* LIBS for TFLITE
* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
#include "tensorflow/lite/micro/micro_interpreter.h"
#include "tensorflow/lite/micro/micro_mutable_op_resolver.h"
#include "tensorflow/lite/schema/schema_generated.h"
#include "tensorflow/lite/micro/micro_error_reporter.h"
#include "tensorflow/lite/micro/all_ops_resolver.h"
#include "tensorflow/lite/micro/system_setup.h"

/* 
* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*  CONFIGURATIONS
* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
#include "conf.h"

// NN CONF
tflite::MicroErrorReporter micro_error_reporter;
tflite::ErrorReporter* error_reporter = &micro_error_reporter;
const tflite::Model* model = nullptr;
tflite::MicroInterpreter* interpreter = nullptr;
TfLiteTensor* input = nullptr;
TfLiteTensor* output = nullptr;
constexpr int kTensorArenaSize = 2*1024;
uint8_t tensor_arena[kTensorArenaSize];
//OTHER CONFS
WiFiClient espClient;
PubSubClient client(espClient);
int computedLayer = 0;
struct tm timeinfo;
UUID uuid;
String MessageUUID = "";
const int nonValidLayer = 999;
int offloadingLayer = nonValidLayer;
bool offloaded = false;
DynamicJsonDocument doc(512); 

/*
 * ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * GENERATE MESSAGE UUID
 * ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
void generateMessageUUID(){
  // Generate a UUID
  unsigned long seed = esp_random();
  uuid.seed(seed);
  uuid.setRandomMode();
  uuid.generate();
  MessageUUID = (String)uuid.toCharArray();
 }

/* 
* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
* LOAD NN LAYER
* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
void loadNNLayer(String model_name){
  // Import del modello da testare -> Nome nell'header file
  if(model_name.equals("mod_0"))model = tflite::GetModel(mod_0);
  if(model_name.equals("mod_1"))model = tflite::GetModel(mod_1);
  if(model_name.equals("mod_2"))model = tflite::GetModel(mod_2);
  if(model_name.equals("mod_3"))model = tflite::GetModel(mod_3);
  if(model_name.equals("mod_4"))model = tflite::GetModel(mod_4);
  if(model_name.equals("mod_5"))model = tflite::GetModel(mod_5);
  if(model_name.equals("mod_6"))model = tflite::GetModel(mod_6);
  if(model_name.equals("mod_7"))model = tflite::GetModel(mod_7);

  if (model->version() != TFLITE_SCHEMA_VERSION) {
      Serial.print("Model provided is schema version not equal to supported!");
      return;
  } else {
      Serial.print("\nModel Layer Loaded! \n");
  }
  // Questo richiama tutte le implementazioni delle operazioni di cui abbiamo bisogno
  tflite::AllOpsResolver resolver;
  tflite::MicroInterpreter static_interpreter(model, resolver, tensor_arena, kTensorArenaSize, error_reporter);
  interpreter = &static_interpreter;
  Serial.print("Interprete ok");

  // Alloco la memoria del tensor_arena per i tensori del modello
  TfLiteStatus allocate_status = interpreter->AllocateTensors();
  if (allocate_status != kTfLiteOk) {
      Serial.println("AllocateTensors() failed");
      return;
  } else {Serial.println("AllocateTensors() done\n");}
}

/* 
* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
* INFERENCE FOR NN LAYER
* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
StaticJsonDocument<512> runNNLayer(int offloading_layer_index){
  
  // Generate the JSON message
  StaticJsonDocument<512> jsonDoc;
  for (int i = 0; i < offloading_layer_index; i++){
    String model_name = "mod_" + String(i);
    float inizio = micros();

    loadNNLayer(model_name);
    input = interpreter->input(0);
    output = interpreter->output(0);
    interpreter->Invoke();
    
    //jsonDoc["Layer"][i] = "nn_layer_"+i;
    jsonDoc["Inference Time (s)"][i] = (micros()-inizio);
    Serial.println("Computed layer: " + String(i)+" Inf Time: " + String(micros()-inizio) );
  }
  return jsonDoc;
}/*

/* 
* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
* WIFI CONFIGURATION
* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
void wifiConfiguration(){
  // Wi-Fi Connection
  WiFi.mode(WIFI_STA);
  WiFi.begin(SSID, PWD);
  Serial.println("Connecting to WiFi...");
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println(".");
    delay(500);
    ESP.restart();
  } 

  Serial.println("Connected to WiFi");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
  
  delay(500);
}

/* 
* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
* MQTT CONFIGURATION
* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
void mqttConfiguration(){
  client.setServer(MQTT_SRV, MQTT_PORT);
  while (!client.connect("ESP32Client", "", "")) {
    Serial.println("Connecting to MQTT Broker");
    if (client.connected()) {
      Serial.println("Connected to MQTT Broker");
    } else {
      Serial.print("Failed to connect to MQTT Broker - retrying, rc=");
      Serial.print(client.state());
      delay(500);
    }
  }
}

/* 
* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
* TIMER CONFIGURATION & FLOATING-POINT TIMESTAMP
* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
String getCurrTimeStr(){
  struct timeval tv;
  gettimeofday(&tv, nullptr);
  time_t currentTime = tv.tv_sec;
  int milliseconds = tv.tv_usec / 1000;
  int microseconds = tv.tv_usec % 1000000;
  char currentTimeStr[30];
  snprintf(currentTimeStr, sizeof(currentTimeStr), "%ld.%03d%03d", currentTime, milliseconds, microseconds);
  String currentTimeString = String(currentTimeStr);
  return currentTimeString;
}

void timeConfiguration(){
  // Configure NTP time synchronization
  configTime(NTP_GMT_OFFSET, NTP_DAYLIGHT_OFFSET, NTP_SRV);
  Serial.println("Connecting to NTP Server");
  // Try obtaining the time until successful
  struct tm timeinfo;
  while (!getLocalTime(&timeinfo)) {
    delay(500);
  }

  // Print current time
  Serial.println(getCurrTimeStr());
  Serial.println("NTP Time Configured");
  return;
}

/* 
* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
* GET OFFLOADING INFORMATION
* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
void getOffloadingInformation() {
  client.subscribe("comunication/edge/nn_offloading");
  // Listen for incoming messages and store the last received message
  client.setCallback([](char* topic, byte* payload, unsigned int length) {
    // Convert the incoming message to a string
    String message = "";
    for (int i = 0; i < length; i++) {
      message += (char)payload[i];
    }

    // Parse the JSON message and store it in the DynamicJsonDocument
    DeserializationError error = deserializeJson(doc, message);
    
    // Check for parsing errors
    if (error) {
      Serial.println(error.c_str());
      return;
    }

    // Access specific fields in the JSON message
    String nn_layer = doc["layer"];
    offloadingLayer = nn_layer.toInt();

    // Print some values from the parsed JSON message
    Serial.print("Offloading Layer: "+ String(nn_layer));
  });
}

/* 


/*
 * ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
* PUBLISH DEVICE ANALYTICS
* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
void publishDeviceAnaytics(){
 // Generate the JSON message
  StaticJsonDocument<512> jsonDoc;
  const int firstRunOffloadingLayer = 8;
  jsonDoc = runNNLayer(firstRunOffloadingLayer);
  jsonDoc["timestamp"] = getCurrTimeStr();
  jsonDoc["messageUIID"] = MessageUUID;
  jsonDoc["nn"] = nn;

  // Serialize the JSON document to a string
  String jsonMessage;
  serializeJson(jsonDoc, jsonMessage);
  // Publish the JSON message to the topic
  client.publish("comunication/device/nn_analytics", jsonMessage.c_str(), 2);
  Serial.println("Published Device Analytics");
}

/* 
 * ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * SETUP 
 * ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 */
void setup() {
  Serial.begin(115200);
  wifiConfiguration();        // Wi-Fi Connection
  mqttConfiguration();        // MQTT
  timeConfiguration();        // Synchronize Timer - NTP server
  generateMessageUUID();      // Generate an Identifier for the message
  getOffloadingInformation(); // Subscribe to a topic to recieve updates about the offloading
  publishDeviceAnaytics();    // Publishes to a topic the inference time of each layer on the device
}

/*
* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
* NN MODEL PREDICT 
* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
void predictAndOffload(){
  if(offloadingLayer != nonValidLayer && !offloaded){
    offloaded = true;

    StaticJsonDocument<512> jsonDocNNOutput;
    StaticJsonDocument<512> jsonDoc;

    //jsonDocNNOutput = runNNLayer(offloadingLayer);

    // Generate the JSON message
    // Fill in the JSON data
    jsonDoc["last_computed_layer"] = ""+String(offloadingLayer)+"";
    jsonDoc["last_layer_output"] = "";
    jsonDoc["timestamp"] = getCurrTimeStr();
    jsonDoc["messageUIID"] = MessageUUID;
    jsonDoc["nn"] = nn;

    // Serialize the JSON document to a string and Publish the JSON message to the topic
    String jsonMessage;
    serializeJson(jsonDoc, jsonMessage);
    client.publish("comunication/device/nn_offloading", jsonMessage.c_str(), 2);
    Serial.println("\nPerformed Offloading from layer: " + String(offloadingLayer));
  }
}

/* 
 * ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * LOOP 
 * ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 */
void loop() {
  client.loop();          
  predictAndOffload();
  if (offloaded){
    delay(5000);
    ESP.restart();
  }
}