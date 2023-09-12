The system is a PCB that contains an ATMega328P-A microcontroller, a pushbutton, and an LED. The brightness of the LED can be switched on and off via the button, and have its brightness set to various levels through the Arduino serial monitor. It supports ignoring serial input when in the off state, 6 different brightness levels, and brightness readout when setting the brightness through entering letters into the serial monitor.

The project is intended to teach individuals how to use PCB design software, namely through KiCad, and how to produce designs that can be produced.

There are no specific installation instructions, the gerber files are ready to be used for PCB manufacture and the parts needed are listed in the documentation paper but will require a little bit of research to find. The code is ready in the ino file in the branch and only needs the Arduino IDE to run.
