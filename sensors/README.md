# Sensors

| Sensor agency | Sensor |
| ------------- | ------ |
| Temperature | lm35 |
| Temperature | mlx90614 |
| Gyro | mpu6050 dmp6 |

## Data Logging

Sources: [Using the SD library to log data](https://www.arduino.cc/en/Tutorial/Datalogger), [Easy Arduino Temperature Logger](http://henrysbench.capnfatz.com/henrys-bench/arduino-projects-tips-and-more/easy-arduino-temperature-logger/)

## Simulating on Fritzing

1. Prototype board circuits on Fritzing.

2. Open ArduinoIDE and on `Tools` select the desired `Port` for simulation.

3. Copy `arduino.exe` path's.

4. Get back to Fritzing and on `Edit/Preferences/Code View` click on `Location`'s `...` and select the `arduino.exe`'s path.

5. Make sure you have selected the right `Board` and the right `Port` on the red tab at the bottom and then hit the `Upload` button.

## Emulating on Proteus

1. Open a new project on Proteus.

2. Select required specs.

3. Move to the `Schematic Capture` tag.

4. Click on `P`.

5. Select Arduino's version you would like to emulate.

Sources: [Simulate Arduino in Proteus - LM35 temprature sensor](https://www.youtube.com/watch?v=Xjgt2Ijyn5g)
