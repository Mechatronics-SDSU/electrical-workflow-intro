#define LED_PIN 9
#define BUTTON_PIN 7

byte lastButtonState;
int ledState = 0;
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
  if (humanInput == 'h' && actualLastButtonState == true) {
    ledState = ledState + 30;
    analogWrite(LED_PIN, ledState);
    Serial.print("Warning: Brightness changed to ");
    Serial.println(ledState);
  } 
  if (humanInput == 'l' && actualLastButtonState == true) {
    ledState = ledState - 30;
    analogWrite(LED_PIN, ledState);
    Serial.print("Warning: Brightness changed to ");
    Serial.println(ledState);
  }
  if (humanInput == 'a' && actualLastButtonState == true) {
    ledState = 255 * 0;
    analogWrite(LED_PIN, ledState);
    Serial.print("Warning: Brightness changed to ");
    Serial.println(ledState);
  }  
  if (humanInput == 'b' && actualLastButtonState == true) {
    ledState = 255 * 0.2;
    analogWrite(LED_PIN, ledState);
    Serial.print("Warning: Brightness changed to ");
    Serial.println(ledState);
  }  
  if (humanInput == 'c' && actualLastButtonState == true) {
    ledState = 255 * 0.4;
    analogWrite(LED_PIN, ledState);
    Serial.print("Warning: Brightness changed to ");
    Serial.println(ledState);
  }  
  if (humanInput == 'd' && actualLastButtonState == true) {
    ledState = 255 * 0.6;
    analogWrite(LED_PIN, ledState);
    Serial.print("Warning: Brightness changed to ");
    Serial.println(ledState);
  } 
  if (humanInput == 'e' && actualLastButtonState == true) {
    ledState = 255 * 0.8;
    analogWrite(LED_PIN, ledState);
    Serial.print("Warning: Brightness changed to ");
    Serial.println(ledState);
  }  
  if (humanInput == 'f' && actualLastButtonState == true) {
    ledState = 255;
    analogWrite(LED_PIN, ledState);
    Serial.print("Warning: Brightness changed to ");
    Serial.println(ledState);
  }  
  if (humanInput == '?') {
    Serial.print("The current brightness level is ");
    Serial.println(ledState);
  }  
}