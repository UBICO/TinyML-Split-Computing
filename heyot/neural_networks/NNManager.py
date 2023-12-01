import tensorflow as tf
import time
import pandas as pd
import logging

logger = logging.getLogger(__name__)

class NNManager:
    def __init__(self, nn_id):
        self.nn_id = nn_id
        self.start_layer_index = None
        self.data = None
        self.update_time = None
        self.model_loading_time = None
        self.model = None
        self.layer_outputs = []
        self.analytics_data = None
        

    def update_csv_file(self, layer_id: int, new_inference_time: float) -> None: 
        """
        After every new execution of the Neural Network, identified by it's id <nn_id>, we updated 
        the .csv file containing it's inference time for each layer with the new computation time
        """
        logger.info(f"Updating the Edge Analytics")
        start_time = time.time()  
        # Initialize the total time
        # Load the existing CSV file
        # csv_file_path = f"./neural_networks/ai_models/{nn_id}/{nn_id}_analytics.csv" 
        # analytics_data = pd.read_csv(csv_file_path)
        # Update the inference time for the specified layer and save the updated data back to the CSV file
        # analytics_data.at[layer_id, 'layer_inference_time'] = new_inference_time 
        # analytics_data.to_csv(csv_file_path, index=False) 
        end_predict = time.time()
        self.update_time = end_predict - start_time
        logger.info(f"Updated the Edge Analytics: {self.update_time}")
    
    def load_model(self):
        logger.info(f"Loading  Neural Network [{self.nn_id}]")
        start_time = time.time()  # Initialize the total time
        try:
            self.model = tf.keras.models.load_model(self.get_tflite_model_path())
        except Exception as e:
            logger.error(f"Can't Load the model for nn with id: {self.nn_id} at path: {self.get_tflite_model_path()}")
            logger.error(f"Error:{e}")

            
        end_time = time.time() # Measure the end time and tot time
        self.model_loading_time = end_time - start_time
        
    def set_input_data(self, layer_input_shape, layer_data):
        return layer_data

    def predic_single_layer(self, layer_id, layer_data):
        layer =  self.model.layers[layer_id] 
        input_data = self.set_input_data(layer_input_shape=layer.input_shape[1:], layer_data=layer_data)
        # Create an intermediate model with the current layer
        intermediate_model = tf.keras.Model(inputs= self.model.input, outputs=layer.output)
        # Predict using the current layer keeps track of the time it takes
        start_predict = time.time_ns() / 1_000_000_000
        try:
            layer_output = intermediate_model.predict(input_data)
        except Exception as e:
            logger.error(f"Can't Predict Layer: {layer_id}")
        end_predict = time.time_ns() / 1_000_000_000
        single_layer_predict_time = (end_predict - start_predict)
        # Updates the analytics of the model with the new inference time
        self.update_csv_file(layer_id=layer_id, new_inference_time=single_layer_predict_time)
        # Append the layer name and output to the layer_outputs list
        self.layer_outputs.append({"name": layer.name, "output": str(layer_output.tolist())})

    def perform_predict(self, start_layer_index, data):
        logger.info(f"Prediction with Neural Network [{self.nn_id}] from layer [{start_layer_index}]")
        self.data = data
        self.load_model()                           # Load the model
        self.start_layer_index = start_layer_index   # Specify the starting layer (0-based index)
        num_layers = len(self.model.layers) 
        # Iterate through the layers starting from the specified index
        [self.predic_single_layer(layer_id, layer_data=data) for layer_id in range(start_layer_index, num_layers)] 
        return self.layer_outputs, self.model_loading_time, self.update_time
    
    def get_tflite_model_path(self) ->str:
        return f'./neural_networks/ai_models/{self.nn_id}/{self.nn_id}.h5'

    def get_model_analytics(self) -> pd.DataFrame:
        self.nn_analytics_path  = f'./neural_networks/ai_models/{self.nn_id}/{self.nn_id}_analytics.csv'
        self.analytics_data = pd.read_csv(self.nn_analytics_path)
        return self.analytics_data 
    