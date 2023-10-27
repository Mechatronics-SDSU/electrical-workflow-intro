





int ledPin = 5;      // LED connected to digital pin 9
int inPin = 7;   // potentiometer connected to analog pin 3
int val = 1;         // variable to store the read value
int brightnessState = 250; //store state when LED turns back on
int previousState = 0;
int userInput = 0;
int fadeOff = 0;
boolean toggle = true;
boolean ledON = false;


void setup() {
  pinMode(ledPin, OUTPUT);  // sets output pin5
  pinMode(inPin, INPUT); // sets input pin7
  Serial.begin(115200);
}

void loop() {
  
  if (Serial.available() > 0) { // read the incoming byte:
    userInput = Serial.read();  // say what you got:
    //Serial.print("I received: ");
    //A
    //Serial.println(userInput, BIN);
    if(ledON){
      if(userInput == 'A'){
          brightnessState = 0;
          Serial.print("New brightness is: ");
          Serial.print((brightnessState / 250.0)* 100, BIN);
          Serial.println(" %");
        }
        else if(userInput == 'B'){
          brightnessState = 50;
          Serial.print("New brightness is: ");
          Serial.print((brightnessState / 250.0)* 100, BIN);
          Serial.println(" %");
        }
        else if(userInput == 'C'){
          brightnessState = 100;
          Serial.print("New brightness is: ");
          Serial.print((brightnessState / 250.0)* 100, BIN);
          Serial.println(" %");
        }
        else if(userInput == 'D'){
          brightnessState = 150;
          Serial.print("New brightness is: ");
          Serial.print((brightnessState / 250.0)* 100, BIN);
          Serial.println(" %");
        }
        else if(userInput == 'E'){
          brightnessState = 200;
          Serial.print("New brightness is: ");
          Serial.print((brightnessState / 250.0)* 100, BIN);
          Serial.println(" %");
        }
        else if (userInput == 'F'){
          brightnessState = 250;
          Serial.print("New brightness is: ");
          Serial.print((brightnessState / 250.0)* 100, BIN);
          Serial.println(" %");
        }
        else if (userInput == '?'){
          Serial.print("Current brightness is: ");
          Serial.print((brightnessState / 250.0)* 100, BIN);
          Serial.println(" %");
        }
        
    }
    else{
      Serial.println("Turn on the LED first");
    }
  }
  
  val = digitalRead(inPin); // check for button press
  
  if(!val){
    analogWrite(ledPin, brightnessState);
    if(toggle){
      ledON = true;
      Serial.println("LED is on");
      Serial.print("Current brightness is: ");
      Serial.print((brightnessState / 250.0)* 100, BIN);
      Serial.println(" %");
    }
    else{
      ledON = false;
      fadeOff = brightnessState;
      while(fadeOff > 0){
        analogWrite(ledPin,fadeOff);
        fadeOff--;
        delay(5);
      }
      analogWrite(ledPin,0);
      Serial.println("LED is off");
      previousState = 0;
    }
    toggle = !toggle;
  }
  
  if(ledON){
    if(previousState != brightnessState){
        while(previousState < brightnessState){
          analogWrite(ledPin, previousState);
          previousState++;
          delay(5A);
        }
        while(previousState > brightnessState){
          analogWrite(ledPin, previousState);
          previousState--;
          delay(5);
        }
    }
      analogWrite(ledPin, brightnessState);
      delay(100);
  }
  
  while(!val){
      val = digitalRead(inPin);
  }
}
