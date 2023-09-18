// C++ code
//

int ledPin = 10;
int buttonPin = 2;
int buttonState = 0;
int prevButtonState;
int incomingByte = 0;
int currBrightness = 0;
bool ledCase = true;

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  // toggle LED on press
  prevButtonState = buttonState;
  buttonState = digitalRead(buttonPin);
  	
  	if ((buttonState == HIGH) && (prevButtonState == LOW)) {
    // turn LED on:
      if (ledCase) {
    	//digitalWrite(ledPin, HIGH);
        
        analogWrite(ledPin, currBrightness);
        Serial.print("Current brightness is at: ");
        Serial.print(currBrightness/2.55);
        Serial.println("%");
        ledCase = false;
      }
    // turn LED off:
      else {
        digitalWrite(ledPin, LOW);
        ledCase = true;
      }
    }
  
  	if (Serial.available() > 0) {
    // read the incoming byte:
    	incomingByte = Serial.read();
      	switch(incomingByte) {
         case('A'):
          	currBrightness = 0;
          	if (!ledCase)
          		analogWrite(ledPin, currBrightness);
          	Serial.print("New brightness is : ");
            Serial.print(currBrightness/2.55);
          	Serial.println("%");
          	break;
  		
         case('B'):
          	currBrightness = 51;
          	if (!ledCase)
          		analogWrite(ledPin, currBrightness);
          	Serial.print("New brightness is : ");
            Serial.print(currBrightness/2.55);
          	Serial.println("%");
          	break;
          
         case('C'):
          	currBrightness = 102;
          	if (!ledCase)
          		analogWrite(ledPin, currBrightness);
          	Serial.print("New brightness is : ");
            Serial.print(currBrightness/2.55);
          	Serial.println("%");
          	break;
          
         case('D'):
          	currBrightness = 153;
          	if (!ledCase)
          		analogWrite(ledPin, currBrightness);
          	Serial.print("New brightness is : ");
            Serial.print(currBrightness/2.55);
          	Serial.println("%");
          	break;
         
         case('E'):
          	currBrightness = 204;
          	if (!ledCase)
          		analogWrite(ledPin, currBrightness);
          	Serial.print("New brightness is : ");
            Serial.print(currBrightness/2.55);
          	Serial.println("%");
          	break;
         
         case('F'):
          	currBrightness = 255;
            if (!ledCase) 
          		analogWrite(ledPin, currBrightness);      
          	Serial.print("New brightness is : ");
            Serial.print(currBrightness/2.55);
          	Serial.println("%");
         	break;
         
         default:
          	if (!ledCase)
          		analogWrite(ledPin, currBrightness);
          	Serial.print("Current brightness is at: ");
            Serial.print(currBrightness/2.55);
          	Serial.println("%");
    }
     
}
}


