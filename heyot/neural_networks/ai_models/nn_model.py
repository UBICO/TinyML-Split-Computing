import numpy as np
import os
from NNBuilder import NNBuilder
import psutil


def print_system_resources():
    # Get CPU usage
    cpu_percent = psutil.cpu_percent(interval=1)
    print(f"CPU Usage: {cpu_percent}%")

    # Get available memory information
    virtual_memory = psutil.virtual_memory()
    print(f"Total Memory: {virtual_memory.total} bytes")
    print(f"Available Memory: {virtual_memory.available} bytes")
    print(f"Used Memory: {virtual_memory.used} bytes")
    print(f"Memory Usage: {virtual_memory.percent}%")


# Function to generate random dataset with the specified number of samples and features
def generate_random_dataset(num_samples, num_features):
    return np.random.rand(num_samples, num_features)

def create_directory_if_not_exists(directory_path):
    if not os.path.exists(directory_path):
        os.makedirs(directory_path)

def build_and_run_nn(random_dataset, model_name, layer_sizes, activation_per_layer):
    print(f"\n### {model_name} ###")
    print(f"input_shape: {random_dataset.shape[1]}.")

    directory_path = f"./{model_name}"
    create_directory_if_not_exists(directory_path)

    predictor = NNBuilder(random_dataset, layer_sizes, model_name, activation_per_layer)
    predictor.load_and_preprocess_data()
    predictor.build_model()
    predictor.train()
    predictor.evaluate()
    predictor.get_model_weight()
    predictor.print_layer_info(num_executions=100)
    predictor.export_layer_info()
    predictor.save_model()

# Example usage 
num_samples = 1000
num_features = 10

# Generate a random dataset
random_dataset = generate_random_dataset(num_samples, num_features)

# Model configurations
model_configs = [
    ("01", [128, 64, 32, 16, 16, 32, 64, 128], ['relu', 'relu', 'relu', 'relu', 'relu', 'relu', 'relu', 'relu']),
    ("02", [256, 128, 64, 32, 16, 8, 4, 2], ['relu', 'relu', 'relu', 'relu', 'relu', 'relu', 'relu', 'relu']),
    ("03", [2, 4, 8, 16, 32, 64, 128, 256], ['relu', 'relu', 'relu', 'relu', 'relu', 'relu', 'relu', 'relu']),
    ("04", [64, 64, 64, 64, 64, 64, 64, 64], ['relu', 'relu', 'relu', 'relu', 'relu', 'relu', 'relu', 'relu'])
]

print_system_resources()


# Build and run models
for model_name, layer_sizes, activation_per_layer in model_configs:
    build_and_run_nn(random_dataset, model_name, layer_sizes, activation_per_layer)

import matplotlib.pyplot as plt
import os
fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(15, 6))

# Plot neuron numbers for each model
neuron_numbers = [sum(config[1]) for config in model_configs]
model_names = [config[0] for config in model_configs]
ax1.bar(model_names, neuron_numbers, color='blue')
ax1.set_xlabel('Model')
ax1.set_ylabel(' Neuron Count')
ax1.set_title('Total Neuron Count for Each Model')

# Plot neural network structure
for config in model_configs:
    model_name, layer_sizes, _ = config
    x = np.arange(len(layer_sizes))
    ax2.plot(x, layer_sizes, marker='o', label=f'Model {model_name}')
ax2.set_xlabel('Layer')
ax2.set_ylabel('Neuron Count')
ax2.set_title('Neural Network Structure of each Model')
ax2.set_xticks(x)
ax2.set_xticklabels([f'Layer {i+1}' for i in x])
ax2.legend()

plt.tight_layout()
plt.show()



# Get the layer sizes in bits for each model
model_names = [config[0] for config in model_configs]
layer_sizes_bits = []

for model_name, layer_sizes, activation_per_layer in model_configs:
    predictor = NNBuilder(random_dataset, layer_sizes, model_name, activation_per_layer)
    predictor.load_and_preprocess_data()
    predictor.build_model()
    layer_sizes_bits.append(sum([size for (_, size) in predictor.get_layer_sizes()]))

# Plot the size of each model in bits
plt.figure(figsize=(10, 6))
plt.bar(model_names, layer_sizes_bits, color='blue')
plt.xlabel('Model')
plt.ylabel('bytes')
plt.title('Total Size (bytes) for Each Model')
plt.show()
