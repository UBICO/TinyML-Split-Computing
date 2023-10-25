import numpy as np
import tensorflow as tf
import pandas as pd
import numpy as np
import time
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler, LabelEncoder
from sklearn.metrics import accuracy_score, precision_score, recall_score, f1_score, confusion_matrix, classification_report
import os
import matplotlib.pyplot as plt

class NNBuilder:
    def __init__(self, dataset, layer_sizes, model_name, activation_per_layer):
        self.dataset = dataset
        self.layer_sizes = layer_sizes
        self.model_name = model_name
        self.activation_per_layer = activation_per_layer
        self.model = None
        self.le = LabelEncoder()
        self.scaler = StandardScaler()
        
    def load_and_preprocess_data(self):
        """
        Preprocess the data. 
        The data is split into training and testing sets.
        """
        # Separate input features (X) and target variable (y)
        X = self.dataset[:, :-1]
        y = self.dataset[:, -1]

        # Convert the target variable to integer labels (if it's not already)
        label_encoder = LabelEncoder()
        y = label_encoder.fit_transform(y)

        # Split the data into training and testing sets
        X_train, X_test, y_train, y_test = train_test_split(
            X, y, test_size=0.2, random_state=42)

        # Save the preprocessed data back to the instance variables
        # self.X_train, self.X_test = X_train, X_test
        # self.y_train, self.y_test = y_train, y_test
        # Save the preprocessed data back to the instance variables
        self.X_train, self.X_test = X_train, X_test
        self.y_train, self.y_test = y_train.flatten(), y_test.flatten()

    """
    def build_model(self):
        try:
            model = tf.keras.Sequential()
            # Add the input layer
            model.add(tf.keras.layers.InputLayer(input_shape=(self.dataset.shape[1] - 1)))
            # Add the hidden layers
            for i, (layer_size, activation) in enumerate(zip(self.layer_sizes, self.activation_per_layer)):
                model.add(tf.keras.layers.Dense(layer_size, activation=activation, name=f'nn_layer_{i+1}'))
            # Add the output layer
            model.add(tf.keras.layers.Dense(1, activation='sigmoid', name='nn_output_layer'))
            print(f"Model [{self.model_name}] built.")
            self.model = model
        except Exception as e:
            print("Can't build the model.")
            self.model = None
    """
    def build_model(self):
        try:
            model = tf.keras.Sequential()
            # Add the input layer
            model.add(tf.keras.layers.InputLayer(input_shape=(self.dataset.shape[1] - 1)))
            # Add the hidden layers
            for i, (layer_size, activation) in enumerate(zip(self.layer_sizes, self.activation_per_layer)):
                model.add(tf.keras.layers.Dense(layer_size, activation=activation, name=f'nn_layer_{i+1}'))
            # Add the output layer
            model.add(tf.keras.layers.Dense(1, activation='sigmoid', name='nn_output_layer'))
            print(f"Model [{self.model_name}] built.")
            self.model = model
        except Exception as e:
            print("Can't build the model.")
            self.model = None
    def train(self, optimizer='adam', loss='binary_crossentropy', metrics=['accuracy'], epochs=20, batch_size=32, validation_split=0.2):
        if self.model is None:
            raise ValueError("The model has not been built yet. Call build_model() first.")
        try:
            self.model.compile(optimizer=optimizer, loss=loss, metrics=metrics)
            self.model.fit(self.X_train, self.y_train, epochs=epochs, batch_size=batch_size, validation_split=validation_split, verbose=0)
            print(f"Model [{self.model_name}] trained.")
        except Exception as e:
            print(f"Error training the model: {e}")

    def evaluate(self):
        if self.model is None:
            raise ValueError("The model has not been built yet. Call build_model() first.")

        loss, accuracy = self.model.evaluate(self.X_test, self.y_test, verbose=False)

        y_pred_probs = self.model.predict(self.X_test, verbose=False)
        y_pred_binary = (y_pred_probs >= 0.5).astype(int)

        # Convert the target variable to a 1D array using ravel()
        self.y_test = self.y_test.ravel()

        # Use 'macro' average for precision, recall, and f1-score
        precision = precision_score(self.y_test, y_pred_binary, average='macro', zero_division=0)
        recall = recall_score(self.y_test, y_pred_binary, average='macro', zero_division=0)
        f1 = f1_score(self.y_test, y_pred_binary, average='macro', zero_division=0)

        # Print the metrics
        print(f"Model [{self.model_name}] evaluated.")
        print(" - Precision:", precision)
        print(" - Recall:", recall)
        print(" - F1 Score:", f1)
        print(f' - Test accuracy: {accuracy}')

        # Print the classification report (includes per-class metrics)
        # print("Classification Report:")
        # print(classification_report(self.y_test, y_pred_binary))

        # Print the confusion matrix
        # conf_matrix = confusion_matrix(self.y_test, y_pred_binary)
        # print("Confusion Matrix:")
        # print(conf_matrix)
        

    def print_layer_info(self):
        if self.model is None:
            raise ValueError("The model has not been built yet. Call build_model() first.")
        print(self.model.summary())

    def get_model_weight(self):
        if self.model is None:
            raise ValueError("The model has not been built yet. Call build_model() first.")
        
        # Create a string buffer to capture the model summary
        import io
        import re
        buffer = io.StringIO()
        
        # Use the string buffer as the output for the model summary
        self.model.summary(print_fn=lambda x: buffer.write(x + '\n'))
        
        # Get the model summary as a string
        model_summary = buffer.getvalue()
        
        # Search for the "Total params" line and extract the information
        total_params_line = [line for line in model_summary.split('\n') if "Total params" in line][0]
        model_weight = total_params_line.replace("Total params", f"Model [{self.model_name}] weight")
        model_weight = re.sub(r'weight: \d+', 'weight:', model_weight).replace("(","").replace(")","")
        print(model_weight)

    def export_layer_info(self):
        if self.model is None:
            raise ValueError("The model has not been built yet. Call build_model() first.")


    def save_model(self):
        converter = tf.lite.TFLiteConverter.from_keras_model(self.model)
        print(self.model.layers)
        tflite_model = converter.convert()
        with open(f'{self.model_name}/{self.model_name}.tflite', 'wb') as f:
            f.write(tflite_model)

        # Save the model to an HDF5 file
        self.model.save(f'{self.model_name}/{self.model_name}.h5')

   
    def get_array_size_in_bits(self, arr):
        return arr.size * arr.itemsize * 8

    def get_layer_sizes(self):
        layer_weights_sizes = []
        for layer in self.model.layers:
            weights = layer.get_weights()
            if weights:
                weight_size_bits = sum(self.get_array_size_in_bits(w) for w in weights)
                layer_weights_sizes.append((layer.name, weight_size_bits))
        return layer_weights_sizes

    def get_layer_times(self, X, y, num_executions=10):
        layer_avg_times = {}

        for layer in self.model.layers:
            total_time = 0.0

            for _ in range(num_executions):
                # Start the timer
                start_time = time.time_ns() /1000000

                # Train the model with a single batch to capture the forward and backward pass times
                self.model.train_on_batch(X[:1], y[:1])

                # Stop the timer
                end_time = time.time_ns() /1000000

                # Accumulate the time taken for this execution
                total_time += end_time - start_time

            # Calculate the average time for this layer
            avg_time = total_time / num_executions
            #avg_time *=1000
            

            # Store the average time for the current layer
            layer_avg_times[layer.name] = avg_time
           # Create a bar plot for average layer sizes

        # Create a bar plot for average training times
        plt.figure(figsize=(12, 6))
        plt.bar(layer_avg_times.keys(), layer_avg_times.values())
        plt.xlabel('Layer')
        plt.ylabel('Average Training Time (s)')
        plt.title(f'Average Training Time for Each Layer (Executions: {num_executions})')
        plt.xticks(rotation=45)
        #plt.show()
        
        # Create the directory if it doesn't exist
        image_folder = f'./{self.model_name}'
        
        # Save the image to the corresponding folder
        image_path = os.path.join(image_folder, f'layer_Infierence_time.png')
        plt.savefig(image_path)
        plt.close()  # Close the plot to release resources

        return layer_avg_times

    def print_layer_info(self, num_executions):
        # Print the sizes of each layer
        layer_sizes = self.get_layer_sizes()
        for layer_name, size_bits in layer_sizes:
            print(f"Layer '{layer_name}': {size_bits} bits")

        # Measure and print the time of computation for each layer during training and inference
        train_layer_times = self.get_layer_times(self.X_train, self.y_train, num_executions)
        test_layer_times = self.get_layer_times(self.X_test, self.y_test, num_executions)
        for layer_name, time_taken in train_layer_times.items():
            #print(f"Layer '{layer_name}': {time_taken:.5f} seconds (training)")
            print(f"Layer '{layer_name}': {test_layer_times[layer_name]:.5f} seconds (inference)")
   
    def export_layer_info(self):
   
        # Calculate the sizes of each layer
        layer_sizes = self.get_layer_sizes()

        # Measure the time of computation for each layer during training and inference
        train_layer_times = self.get_layer_times(self.X_train, self.y_train)
        test_layer_times = self.get_layer_times(self.X_test, self.y_test)

        # Initialize an empty list to store the data
        data = []

        # Loop over each layer
        for layer_name, size_bits in layer_sizes:
            # Get the training and inference times for the current layer
            train_time = train_layer_times.get(layer_name, np.nan)  # Return NaN if the layer is not found
            inference_time = test_layer_times.get(layer_name, np.nan)  # Return NaN if the layer is not found

            # Append the current layer's data to the list
            data.append([layer_name, size_bits, train_time, inference_time])

        # Create a DataFrame from the list
        df = pd.DataFrame(data, columns=['Layer', 'Size (bits)', 'Training Time (s)', 'Inference Time (s)'])

        # Export the DataFrame to a CSV file
        df.to_csv(f'{self.model_name}/{self.model_name}_analytics.csv', index=False)

    def create_neuron_image(self):
        if self.model is None:
            raise ValueError("The model has not been built yet. Call build_model() first.")
        
        layer_names = [layer.name for layer in self.model.layers]
        num_layers = len(layer_names)
        max_neurons = max([layer.output_shape[-1] for layer in self.model.layers if hasattr(layer, 'output_shape')])
        
        fig, axs = plt.subplots(1, num_layers, figsize=(num_layers * 5, 5))
        plt.subplots_adjust(wspace=0.5)
        
        prev_neuron_count = 0
        
        for i, layer_name in enumerate(layer_names):
            layer = self.model.get_layer(layer_name)
            weights = layer.get_weights()
            
            if len(weights) > 0:
                neuron_count = weights[1].shape[0]  # Number of neurons in this layer
                
                # Vertical arrangement of dots representing neurons with adjusted spacing and color gradients
                if neuron_count > prev_neuron_count:
                    spacing = 0.4
                else:
                    spacing = 1.0

                dot_size = 200 / max_neurons  # Adjust the dot size based on the maximum number of neurons
                
                if neuron_count > max_neurons:
                    neuron_count_display = max_neurons
                else:
                    neuron_count_display = neuron_count

                color = sns.color_palette("coolwarm", as_cmap=True)(neuron_count / max_neurons)
                
                axs[i].scatter(np.ones(neuron_count_display) * i, range(neuron_count_display),
                               c=[color] * neuron_count_display, s=dot_size)
                axs[i].set_title(f'Layer: {layer_name}\nNeurons: {neuron_count}')
                axs[i].set_xlabel('Layer')
                axs[i].set_ylabel('Neuron')
                axs[i].set_yticks([])  # Hide y-axis labels
                axs[i].set_xticks([])  # Hide x-axis labels
                
                if neuron_count > max_neurons:
                    axs[i].text(i, max_neurons * 0.5, '..', fontsize=20, va='center', ha='center')
                    
                prev_neuron_count = neuron_count
        
        # Create the directory if it doesn't exist
        image_folder = f'./{self.model_name}'
        
        # Save the image to the corresponding folder
        image_path = os.path.join(image_folder, f'neuron_image.png')
        plt.savefig(image_path)
        plt.close()  # Close the plot to release resources
        print(f"Neuron image saved in {image_path}")


