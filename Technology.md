# Technology

## Core: Three main parts
- Smart Semaphore
- Local Area Station
- Web Dashboard

### Smart Semaphore
It is the main component of our project: its main purpose is to detect the presence of a traffic jam and adjust the traffic lights to reduce it.

Are used for the detections **a camera with and integrated ESP-32** to capture the images and send them to a **local area station**, **pollution sensor** that detects the current salubrity of the air, a **microphone** that allows to detect the presence of an emergency vehicle and a **voltage sensor** that allows us to detect the status of the semaphore.
The data between the camera and the local area station is exchanged via WiFi.
The sensors are controlled by a ESP-32 board.

### Local Area Station
It is a raspberryPI that collects all the data form the semaphores of the cross. It elaborates the data and sends it via internet to the remote AWS that calculates the best configuration for the semaphores. Every semaphore has an unique id for identification.

### Web Dashboard
It is composed by the remote server (using **Aws services and nodejs**) and by the frontend (web page and eventually an app). It displays the current status of the semaphores and allows to tweak the parameters of the algorithm that controls them.

## Sensors


### Camera with ESP32
<img src="https://github.com/mralko99/Iot-Project/blob/main/img/camera_esp32.jpg" width="400">

### Air Quality Sensor
<img src="https://github.com/mralko99/Iot-Project/blob/main/img/air_sensor.jpg">

### Microphone
<img src="https://github.com/mralko99/Iot-Project/blob/main/img/microphone.jpg" width="400">

### Voltage Sensor

<img src="https://images-na.ssl-images-amazon.com/images/I/51HVZdowtJL._AC_SL1001_.jpg"  width=400/>


## Actuators

### Relay Module

<img src="https://github.com/mralko99/Iot-Project/blob/main/img/relay_module.jpg" width="400">>


## Communication
- **Camera-to-Local Area Station Communication** is via WiFi. Periodically are sent packets with the status of the sensor.
- **Sea Station-to-Cloud Communication**  via internet with a ethernet/4G connection that guarantees a good throughput.
