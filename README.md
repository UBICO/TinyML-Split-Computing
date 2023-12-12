# HEYoT Neural Network Offloading Example
What about an Offloading Algorithm and some Split Computing?

# Configurations
After giving us a star: You can download the repo and then start to configure all the infrastracture...

Within the folder "environment" you can find the ".env.dev" file. This file sets the variables for the MQTT Client running on the Edge and other parameters for the DJango Web App.

Another important file that needs to be configured is contained in the folder "esp32_board/nn_runner/src" and it's the "conf.h" file. This file contains the configurations of: WiFi, MQTT and NTP server for the device and the edge.


# The Neural Network Model
Inside the folder "heyot/neyral_networks/ai_models" you can find all the utils used for  examples of nn model generation and conversion.
The jupyter notebook "ConvertModel" can give you an idea on how to obtain a single header file for each layer of your neural network model - these header files are key components of the code that then runs on the ESP32 devices.


Each model that you wat to run should be put in the models subdirectory with this structure:
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


