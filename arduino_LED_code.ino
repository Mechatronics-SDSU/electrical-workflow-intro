#define LED_PIN 9
#define BUTTON_PIN 7

byte lastButtonState;
byte ledState = 0;
bool actualLastButtonState = false;
void setup()
{
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  lastButtonState = digitalRead(BUTTON_PIN);
}

void loop()
{
  byte buttonState = digitalRead(BUTTON_PIN);
  if (buttonState != lastButtonState) {
    lastButtonState = buttonState;
    if (buttonState == LOW) {
      if(ledState > 0) {
        ledState = 0;
        actualLastButtonState = false;

      }
        else {
          ledState = 127;
          actualLastButtonState = true;
        }
        analogWrite(LED_PIN, ledState);

    }
  }
   char humanInput = Serial.read();
  {
   if (actualLastButtonState == true)

   {
      if (humanInput == 'a') {
        ledState = 255 * 0;
        analogWrite(LED_PIN, ledState);
        Serial.println("Brightness changed to 0%");
      }
      if (humanInput == 'b') {
        ledState = 255 * 0.2;
        analogWrite(LED_PIN, ledState);
        Serial.println("Brightness changed to 20%");
      }
      if (humanInput == 'c') {
        ledState = 255 * 0.4;
        analogWrite(LED_PIN, ledState);
        Serial.println("Brightness changed to 40%");
      }
      if (humanInput == 'd') {
        ledState = 255 * 0.6;
        analogWrite(LED_PIN, ledState);
        Serial.println("Brightness changed to 60%");
      } 
      if (humanInput == 'e') {
        ledState = 255 * 0.8;
        analogWrite(LED_PIN, ledState);
        Serial.println("Brightness changed to 80%");
      }
      if (humanInput == 'f') {
        ledState = 255;
        analogWrite(LED_PIN, ledState);
        Serial.println("Brightness changed to 100%");
      }
      if (humanInput == '?') {
        ledState = (100 * ledState)/255;
        Serial.print("The current brightness level is ");
        Serial.print(ledState ); 
        Serial.println("%");
      }
   }
  } 
}
}

void loop() {
  // put your main code here, to run repeatedly:

}
