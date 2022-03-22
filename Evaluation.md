A separate mark-down document in the repository (called "Evaluation") providing details on how to performance of the product/service will be evaluated, (i) during the development of the project, (ii) when the first complete version of the system will be ready for use. The document needs to describe the evaluation methodology for both the overall system as well as each individual components and define specific key performance indicators that will be measured, tools that will be used.
The document should clearly address the following aspects:

###The evaluation of the performance of the network technologies.
    We would like to use wifi connection to get a good througput of the video data, without any packet loss
###The evaluation of the performance of the embedded devices in terms of power consumption and energy efficiency.
    The esp32 with a continuous camera feed will consume good amount of energy, so it would be impossible to make this devices remote, they will be powered by direct current as the raspberry that is used for all the connection with the semaphore and internet.
###The evaluation of the response time from an end-user point of view.
    The response time is very important since it's representative of the efficency of the system, the system should correctly detect veichle and pedestrian and act fast to change the traffic light to adapt the traffic flow
