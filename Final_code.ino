
uint8_t led_pin = 10; //the LED pin output
uint8_t button_pin = 13; //the button pin input
bool button = true; //this keeps track of what the button is doing
char input = 'A'; //this is what I will get from the Serial.read()
uint8_t led_state = 0; //what % the button will be at
bool switcher = true; //allows the button to toggle and act as a switch

void setup() {
  pinMode(led_pin, OUTPUT); //just starting everything
  pinMode(button_pin, INPUT);
  Serial.begin(115200);
}

void loop() {
  if (Serial.available() > 0) { //just seeing if there is anything worth reading
      input = Serial.read(); //capturing what is being sent over serial
      
      if (input == 'A') {   //this just determines what brightness goes with the inputed letter
        led_state = 0;
      } else if (input == 'B') {
        led_state = 1;
      } else if (input == 'C') {
        led_state = 2;
      } else if (input == 'D') {
        led_state = 3;
      } else if (input == 'E') {
        led_state = 4;
      } else if (input == 'F') {
        led_state = 5;
      } else if (input == '?') {
        Serial.print("Current Brightness: "); // this prints the brighness info for the input of "?"
        Serial.print(led_state*20);
        Serial.println("%");
      }

      if (input != '?' && input >= 'A' && input <= 'F') //this is the time it prints the led brighness for all changes that are not "?"
        Serial.print("New Brightness: ");
        Serial.print(led_state*20);
        Serial.println("%");
      }
  }

  if (digitalRead(button_pin) && !button) { switcher = !switcher; } //Checks to see if the button has been pressed and if had been pressed or not
  analogWrite(led_pin, led_state*51*switcher); //ths converts the brightness set in led_state to something useable and then it multiplys it with stuff so it all works out and the light can turn off (id est if switcher is 0 then it will turn it off because button turned it off  ;)
  button = digitalRead(button_pin); //this just checks and saves what the button state is so we can compare and see if the buttn was pressed next time...
  delay(50);
}
