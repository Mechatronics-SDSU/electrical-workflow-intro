Fall 2023 Mechatronics Intro Project

Overview:
	This project's goal was to use an Ardunio Uno to toggle an LED using a pushbutton,
while also accepting user inputs through the serial monitor to adjust the LED's brightness.
The LED is only turned on/off by the pushbutton regurdless of user input. After simulating the
circuit on Tinkercad, I was to create a PCB design in KiCad for the circuit.


Instiallation Instructions:
	To build the circuit you must procure an Arduino Uno R3, one push button, one LED, and two
resistors(10k,300), and a breadboard.

	First: Connect the Uno's 5V and GND to the breadboard.
	Second: Connect the 5V and GND to the push button and place 10k resistor between button and GND.
	Third: Connect the 330 resistor and LED in series and connect to GND.
	Fourth: Connect the LED+330 to a PWM pin of the Arduino.
	Fith: Connect the pushbutton output to a non-PWM pin of the Arduino.


Usage Guide:
	Once everything is installed correctly, the user must just provide code to the Arduino.
The user must set the PWM pin used to OUTPUT and the pin connected to the push button to INPUT.
	
	Example:
	  #define LED_PIN 5
	  #define BUTTON_PIN 4
	  pinMode(LED_PIN, OUTPUT);
 	  pinMode(BUTTON_PIN, INPUT);

	Once the pin configuration is finished, upload the rest of the code found in the
	 .ino file and your setup is complete.

	Serial Inputs:
	'A' - 0% Brightness
	'B' - 20% Brightness
	'C' - 40% Brightness
	'D' - 60% Brightness
	'E' - 80% Brightness
	'F' - 100% Brightness
	'?' - Check Current Brightness
	
