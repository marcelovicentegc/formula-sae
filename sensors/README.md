# Sensors

| Sensor agency          | Sensor       |
| ---------------------- | ------------ |
| Temperature            | lm35         |
| Temperature (infrared) | mlx90614     |
| Gyro                   | mpu6050 dmp6 |

## Data Logging

| Method                                         | Status    |
| ---------------------------------------------- | --------- |
| .txt (Serial capture to a file via Processing) | Covered   |
| .xls (Serial capture to a file via Processing) | Covered   |
| SD card                                        | Uncovered |
| Database (via HTTP/MQTT)                       | Uncovered |

Useful resources: [Using the SD library to log data](https://www.arduino.cc/en/Tutorial/Datalogger), [Easy Arduino Temperature Logger](http://henrysbench.capnfatz.com/henrys-bench/arduino-projects-tips-and-more/easy-arduino-temperature-logger/), [How can I save data directly in the PC using an Arduino UNO?](https://www.researchgate.net/post/How_can_I_save_data_directly_in_the_pc_using_an_Arduino_UNO), [Connecting Arduino to Processing](https://learn.sparkfun.com/tutorials/connecting-arduino-to-processing/all),
[How to save data from Arduino to a .csv file using Processing](https://www.hackerscapes.com/2014/11/how-to-save-data-from-arduino-to-a-csv-file-using-processing/), [Display Arduino time without a RTC](https://www.youtube.com/watch?v=Jwdoah5Fg5g)

## Notes on Arduino

Useful reources: [Arduino Mega specs](http://www.mantech.co.za/datasheets/products/A000047.pdf)

## Notes on Arduino + Processing

In order for Processing and Arduino to work together when data logging to host, Arduino's Serial Monitor must not be initialized, as Processing will listen to it's process and they might conflict.

Useful resources: [Processing serial port error](https://stackoverflow.com/questions/25569040/processing-serial-port-error)
