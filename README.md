# HEYoT Neural Network Offloading Example

Explore the power of Offloading Algorithms and Split Computing with the HEYoT Neural Network Offloading Example.

## Configurations

Thank you for considering our project! To get started, follow these steps:

1. **Star the Repo:**
   Please show your support by giving our repository a star.

2. **Download and Configure:**
   Clone or download the repository, then proceed with the configuration of the infrastructure.

   - **MQTT Client and Django Web App:**
     Navigate to the "environment" folder and configure the ".env.dev" file. This file manages variables for the MQTT Client running on the Edge and other parameters for the Django Web App.

   - **ESP32 Board Configuration:**
     Find the "conf.h" file inside the "esp32_board/nn_runner/src" folder. This file contains configurations for WiFi, MQTT, and NTP server for both the device and the edge.

## The Neural Network Model

In the "heyot/neural_networks/ai_models" folder, you'll discover utilities for generating and converting neural network models. The Jupyter notebook "ConvertModel" provides insights into obtaining a single header file for each layer of your neural network model. These header files are crucial components of the code that runs on ESP32 devices.

Ensure that each model you want to run follows this directory structure:

<model_name>/
    analytics_data/
        analytics.csv
    data/
        ...
    layers/
        h/
        h5/
        tflite/
    pred_data/
    <moel_name>.h
    <model_name>.h5
    <model_name>.tflite


## Enjoy
Feel free to explore and experiment with different models within the designated "models" subdirectory.

Your contributions and feedback are highly appreciated. Happy coding!
