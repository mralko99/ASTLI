# Technology

## Core: Four main parts
- Connected Camera
- Local Area Station
- Cloud Computing
- Web Dashboard

### Connected Camera
It is the main component of our project: its main purpose is to detect the presence of a traffic jam.
The camera has a system to create an ap if it has problem to connect to the internet.
On this system we have a web page that will allow the user to connect to the camera and to change the wifi settings.
The camera is a http server, that accepts request, and sends the frames to the local area station.

### Local Area Station
On our local area station we have a docker container that makes request to the camera and detect the objects.
We also have a container that will implement a finite state machine that will control the semaphore.
At the end of the stack we have a relay board that will control the junction.

### Wheather Station
It's an arduino 1010 that it's connected to the air quality sensor, temperature/humidity sensor and a microphone to record the audio pollution.
All this data is then transmitted to the cloud.

### Cloud Computing
The data recieved from the raspberryPI(finite state machine staatus and predictions) is stored on the cloud.
We also collect all the data from the weather station and store it on the cloud.
We process all this information and in case we detect some high level schema on the traffic we can adjust the semaphores.

### Web Dashboard
It is composed by the remote server (using **AWS services and nodejs**) and by the frontend (web page and eventually an app).
It displays the current status of the semaphores, all the data from the sensors and it displays the detection made from the system.
It can also make the user change the status of the semaphore from the web view.

## Sensors


### Camera with ESP32
<img src="https://github.com/mralko99/Iot-Project/blob/main/img/camera_esp32.jpg" width="400">

### Air Quality Sensor
<img src="https://github.com/mralko99/Iot-Project/blob/main/img/air_sensor.jpg" width="400">

### Microphone
<img src="https://github.com/mralko99/Iot-Project/blob/main/img/microphone.jpg" width="400">

### Current Sensor

<img src="https://github.com/mralko99/Iot-Project/blob/main/img/current-sensor.jpg"  width="400">


## Actuators

### Relay Module

<img src="https://github.com/mralko99/Iot-Project/blob/main/img/relay_module.jpg" width="400">


## Communication
- **Camera-to-Local Area Station Communication** is via WiFi. Periodically are sent packets with the status of the sensor.
- **Sea Station-to-Cloud Communication**  via internet with a ethernet/4G connection that guarantees a good throughput.