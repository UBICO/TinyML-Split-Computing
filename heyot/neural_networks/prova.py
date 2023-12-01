from NNManager import NNManager
import tensorflow as tf
from tensorflow.keras.preprocessing.text import Tokenizer
from tensorflow.keras.preprocessing.sequence import pad_sequences

def predic_single_layer(model, layer_id, layer_data):
    layer = model.layers[layer_id]
    layer_outputs = []
    input_data = layer_data

    # Create an intermediate model with the current layer
    intermediate_model = tf.keras.Model(inputs=model.input, outputs=layer.output)

    # Predict using the current layer keeps track of the time it takes
    try:
        layer_output = intermediate_model.predict(input_data)
        # Append the layer name and output to the layer_outputs list
        layer_outputs.append({"name": layer.name, "output": str(layer_output.tolist())})
    except Exception as e:
        print(f"Can't Predict Layer: {layer_id}")
        layer_output = None  # Assign None in case of exception

    return layer_outputs, layer_output  # Return both layer_outputs and the output for the next layer

def perform_predict(model, start_layer_index, data):
    print(f"Prediction from layer [{start_layer_index}]")
    layer_data = data
    num_layers = len(model.layers)
    output_data = None
    
    # Iterate through the layers starting from the specified index
    for layer_id in range(start_layer_index, num_layers):
        layer_outputs, output_data = predic_single_layer(model, layer_id, layer_data)
        print(layer_outputs)  # You can print or save layer_outputs as needed
        layer_data = output_data  # Pass the output of the current layer as the input to the next layer

    return layer_outputs

def preprocess_text(texts, tokenizer, max_sequence_length):
    sequences = tokenizer.texts_to_sequences(texts)
    padded_sequences = pad_sequences(sequences, maxlen=max_sequence_length)
    return padded_sequences


model = tf.keras.models.load_model("ai_models/sentiment_model/sentiment_model.h5")

# Example usage:
tokenizer = Tokenizer()  # Create a tokenizer
texts = ["nice nice nice"]

# Assuming you have a tokenizer fitted on your training data
# tokenizer.fit_on_texts(training_texts)

preprocessed_data = preprocess_text(texts, tokenizer, max_sequence_length=2)

# Now, you can pass the preprocessed_data to the perform_predict function
print(perform_predict(model, 0, preprocessed_data))
