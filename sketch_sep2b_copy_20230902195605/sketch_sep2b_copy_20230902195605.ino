const int ledPin = 9;
const int buttonPin = 2;
bool ledState = LOW;
bool lastButtonState = HIGH; 
int currentBrightness = 0; // Ranges from 0-5


void setup() {
  analogWrite(ledPin,0);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); // Start serial communication at 9600 baud rate
}

void loop() {

  bool currentButtonState = digitalRead(buttonPin);
  if(lastButtonState == HIGH && currentButtonState == LOW){
    ledState = !ledState;

    if(ledState == HIGH){
      fadeIn();
    }else{
      fadeOut();
    }
    delay(150);
  }
  if (Serial.available()) {
    char input = (char)Serial.read(); // Read the incoming byte
    if (input == '?') {
      Serial.print("Current Brightness: ");
      Serial.print((currentBrightness / 5.0) * 100);
      Serial.println("%");
    } 
    else {
            switch (input) {
            case 'a':
            case 'A':
              currentBrightness = 0;
              Serial.print("New Brightness: ");
              Serial.print((currentBrightness / 5.0) * 100);
              Serial.println("%"); 
              break;
            case 'b':
            case 'B':
              currentBrightness = 1;
              Serial.print("New Brightness: ");
              Serial.print((currentBrightness / 5.0) * 100);
              Serial.println("%"); 
              break;
            case 'c':
            case 'C':
              currentBrightness = 2; 
              Serial.print("New Brightness: ");
              Serial.print((currentBrightness / 5.0) * 100);
              Serial.println("%");
              break;
            case 'd':
            case 'D':
              currentBrightness = 3; 
              Serial.print("New Brightness: ");
              Serial.print((currentBrightness / 5.0) * 100);
              Serial.println("%");
              break;
            case 'e':
            case 'E':
              currentBrightness = 4;
              Serial.print("New Brightness: ");
              Serial.print((currentBrightness / 5.0) * 100);
              Serial.println("%");
              break;
            case 'f':
            case 'F':
              currentBrightness = 5; 
              Serial.print("New Brightness: ");
              Serial.print((currentBrightness / 5.0) * 100);
              Serial.println("%");
              break;
            default:
            Serial.println("Invalid input");
            break;
            }
          }
      
      int pwmValue = map(currentBrightness, 0, 5, 0, 255);
      analogWrite(ledPin, pwmValue);
      
    }
    
  }
void fadeIn() {
  for (int i = 0; i <= 255; i++) {
    analogWrite(ledPin, i);
    delay(5); // You can adjust this value to change the fade speed
  }
}

void fadeOut() {
  for (int i = 255; i >= 0; i--) {
    analogWrite(ledPin, i);
    delay(5); // You can adjust this value to change the fade speed
  }
}
 