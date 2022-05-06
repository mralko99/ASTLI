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

1. we choose to focus on detection of cars and pedestrian and with a finate state machine control the semaphore
2. reduce wait time on traffic lights, so to reduce pollution that we measure with a sensor
3. the main idea is to get the energy from the cross lights
4. our system is not limited by the framerate of the camera, it's restricted by the speed of the deep learning model
5. To run an Object detection AI we will do it on a Raspberry Pi
6. To run ML on the edge as said before we will use a Raspberry pi and implement a Federated ML algorithm
7. The system should detect and predict every 1 second the bbox so the finate state machine could update the state of the junction accordingly
8. Whitelisting all the devices on the network so that only prerouted connections works


## Changes

### Concept
-We decided to remove the feature of speed trapping, so to block speeding cars.
-We decided to remove the feature of turning off the semaphore.

### Architecture
We decided to try the detection on the edge, we would like to implement a queque on a raspberry pi to make the detection near realtime.

#### Connected Camera [Implemented]
Instead the ESP-32 is used to capture the images from the semaphore and then stream it to the Rasberry Pi.
- **ESP-32 streaming video**: we implemented a streaming server on the ESP-32 that will be interrogated by a docker container on the Raspberry Pi.
-  We also implemented a page for the managment of the wifi connection of the ESP-32, that will pop-up in case of a connection problem of the camera.
-  We also 3d printed an enclosure for the camera

#### Local Area Station [1/3 Implemented]

Local Area Station has been implemented with Raspberry pi and a relay board, because we have no power management problems, and we need more computational power to handle the camera and the image recognition system.

The Local Area Station should serve 3 purpose:

- **Traffic recognition system** [Implemented]: that makes a http request to the connected camera of the frames and analyzes them to detect the objects.
- **Finite state machine** [Not Implemented]: It takes the output of the traffic recognition system and takes a decision on which semaphore to switch.
- **Actuators** [Not Implemented]: The raspberry pi with the output of the finite state machine will control the relay board and so it will control the junction

#### Sensing station [Not Implemented]
The Arduino is used to attach all the sensors, all the data is then transmitted to the Cloud to elaborate and track the data.

#### AWS [Not Implemented]
It's used to have an interface with all the sensing data and to force a state on the local area station.

### Evaluation
For the evaluation:
- we still need to estimate the **power consumption** of single camera
- we still need to estimate the **power consumption** of the local area station
- we still need to estimate the **power consumption** of the sensing station
- we evaluated that the **NN** makes 3 detection every second 
- we still need to estimate the **latency** in the whole system
