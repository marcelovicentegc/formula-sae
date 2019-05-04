# 🤖 Prototypes

## Simulating on Fritzing

1. Prototype board circuits on Fritzing.

2. Open ArduinoIDE and on `Tools` select the desired `Port` for simulation.

3. Copy `arduino.exe` path's.

4. Get back to Fritzing and on `Edit/Preferences/Code View` click on `Location`'s `...` and select the `arduino.exe`'s path.

5. Make sure you have selected the right `Board` and the right `Port` on the red tab at the bottom and then hit the `Upload` button.

## Emulating on Proteus

1. Open a new project on Proteus 8 Professional.

2. Select required specs.

3. Move to the `Schematic Capture` tag.

4. Click on `P`.

5. Select Arduino's version you would like to emulate.
    - If the Arduino version you want is not available, look for it online, or build one.
    - If that was the case and you want to prototype over an `Arduino Mega 2560`, follow these steps:
        1. Extract [this zip file](https://github.com/marcelovicentegc/formula-sae/blob/master/sensors/__prototypes__/assets/Arduino%20Mega%202560%20Library%20for%20Proteus.rar).
        2. Grab the `ArduinoUnoTEP.LIB` and `ArduinoUnoTEP.IDX` files and move them to Proteu's `LIBRARY` folder.
        3. Be happy

6. Set components, currents, voltages, grounds, etc up following your [Arduino's PIN mapping table](https://www.arduino.cc/en/Hacking/PinMapping2560)

7. Open the Arduino IDE and...
    - Make sure the `compilation` box is checked on `File/Preferences/Settings`. I.g: `Show verbose output during: [x] compilation [ ] upload`
    - Make sure the board is aligned with Proteus board.
    - Run `Verify`
    - After compiling, copy the output line that has `.hex`. It will look something like this, if you are on a Windows: `"C:\\Users\\MARCEL~1\\AppData\\Local\\Temp\\arduino_build_138707/sketch_may02a.ino.hex"`

8. Back to Proteus:
    - Click on the Arduino component.
    - Paste on the `Program File:` line the copied `.hex` path.
    - Click `Ok`.
    - Press play on the bottom left corner.

Sources: [Simulate Arduino in Proteus - LM35 temprature sensor](https://www.youtube.com/watch?v=Xjgt2Ijyn5g), [How to add a new library in Proteus 8](https://www.theengineeringprojects.com/2018/04/how-to-add-new-library-in-proteus-8.html)
