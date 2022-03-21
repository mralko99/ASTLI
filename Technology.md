# Technology

## Core: Three main parts
- Smart Semaphore
- Local Area Station
- Web Dashboard

### Smart Semaphore
It is the main component of our project: its main purpose is to detect the presence of a traffic jam and adjust the traffic lights to reduce it.

Are used for the detections **a camera with and integrated ESP-32** to capture the images and send them to a **local area station**, **pollution sensor** that detects the current salubrity of the air, **solar panels** that permits a longer battery life.
A **LoRa module** is used to transmit data from the Semaphore to the Local Area Station (its model in practice is a common bluetooth module).
TODO
The sensors are controlled by a ESP-32 board.

### Local Area Station
It is a raspberryPI that collects all the data form the semaphores that are in predetermined span. It elaborates the data and sends it to the remote AWS that calculates the best configuration for the semaphores. Every semaphore has an unique id for identification.

### Web Dashboard
It is composed by the remote server (using **Aws services and nodejs**) and by the frontend (web page and eventually an app). It displays the current status of the semaphores and allows to tweak the parameters of the AI.

## Sensors


### RaspberryPI with a LoRa antenna
![Img](https://github.com/mralko99/Iot-Project/blob/main/img/Raspberry-Lora.png)
