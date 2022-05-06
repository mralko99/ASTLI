# Second delivery

## Comments from first delivery
1. very rich project with clear problems, but prioritize and focus on one or two at most
2. what are the requirements?
3. are you getting energy from the crosslights?
4. frame rate expected?
5. do you have enough resources to run ML algorithms?
6. Can you bring ML on the edge?
7. Nice end-user metrics how do you translate them in low level requirements
8. security and safety? It is fundamental in this kind of projects

Now for each of the previous points we explain our decisions:

3. the main idea is to get the energy from the cross lights
5. To run an Object detection AI we will try to to it on a Raspberry Pi
6. To run ML on the edge as said before we will use a Raspberry pi and implement a Federated ML algorithm


## Changes

### Concept
No changes has been done.

#### Cloud service
We decided to address the comment from our first delivery so our cloud service will only collect the data from the semaphore and make it available in a dashboard for the end user.

### Evaluation

## Presentation of technical work

For the technical work, we present a list of the functionalities we implemented in different devices.

### Smart Camera

Smart Camera has been divided in two parts, so in two devices, that are the Arduino 1010 board and the ESP-32 board. The Arduino is used to attach to it all the sensors and actuator, so it will send the recorded values to the Local Area Station and will also recive the correct status for the semaphore.
Instead the ESP-32 is used to capture the images from the semaphore and then stream for the Rasberry Pi that the will send all
- **ESP-32 streaming video**: we implemented a streaming server on the ESP-32 that will be interrogated by the Raspberry Pi. We also implemented a page for the managment of the wifi connection of the ESP-32.

### Local Area Station

Local Area Station has been implemented with Raspberry pi, because we have no power management problems, and we need more computational power to handle the camera and the image recognition system. We have three main modules:

- **Traffic recognition system**: that takes pictures of the current situation and analyzes them to understand what the best configuration is for the semaphore.

## Missing functionalities
### Smart Camera
We have to implement the collection of the data from the sensors and the actuation of the semaphore.
### Local Area Station
We still have to implement the comunication with the cloud and 

## Evaluation
For the evaluation:
- we estimated the **power consumption** of single subsytems
- we evaluated **performances of the NN**
- we estimated the **latency** in the whole system

## Evaluation for the 3rd delivery
We want to obtain the correct estimation of the previous parameters with the real prototype.
