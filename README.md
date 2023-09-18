This system takes in an input A-F to change the brightness of an LED. This LED is also controlled by a button. When the button is pressed it turns the LED on, when the button is pressed again it turns the LED off. This is done on a high level by creating two circuits using an arduino and a breadboard, the button uses a pull-down resistor to guarantee a more precise output. After the button is pressed it switches the pin for the LED on which lights it up. On a low level, it uses the ATmega328P as a power supply and pin outputs, this goes through the tracks to interact with other parts of the board to function similarly to what was stated above.

The main challenges faced were learning how to create a proper schematic to make the PCB and learning how to create the basic circuit needed for the tinkercad simulation to run properly. I fixed most of this by finding guides online on what steps I needed to take to make it properly. This was overall a challenge but I learned a lot, the high level simulation works as expected and the PCB clears all design checks.

The parts used to make the board were a SPST button, an LED, an ATmega328P-A, two 10k ohm resistors, one 330 ohm resistor, the AVR-ISP-6, two capacitors, and a crystal. 
