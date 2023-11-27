#ifndef CONF_H_
#define CONF_H_

// ------------------------------------------------------------------------------------------------------------------------------------------------------
// WiFi Conf Hotspot
const char* SSID                = "";
const char* PWD                 = "";
// ------------------------------------------------------------------------------------------------------------------------------------------------------
// MQTT Conf
const char* MQTT_SRV            = "hostaname.local"; // .local is needed when using Hotspot so i will leave it by default
const int MQTT_PORT             = 1883;
const char* MQTT_USR            = ""; 
const char* MQTT_PWD            = ""; 
// ------------------------------------------------------------------------------------------------------------------------------------------------------
// NTP Timer Configuration
const char* NTP_SRV             = "0.it.pool.ntp.org";
const long NTP_GMT_OFFSET       = 0;
const int NTP_DAYLIGHT_OFFSET   = 0;
// ------------------------------------------------------------------------------------------------------------------------------------------------------
#endif // CONF_H
