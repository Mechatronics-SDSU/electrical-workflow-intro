int pwmPin = 3;
int brightnessValue = 0;
int previousBrightnessValue;

int buttonPin = 2;
int buttonState;
int lastButtonState;

boolean toggle = false;

char previousBrightnessLevel;

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  pinMode(pwmPin, OUTPUT);
  Serial.println("Hello! Please enter desired brightness level.");
  Serial.println("A -> 0%   brightness");
  Serial.println("B -> 20%  brightness");
  Serial.println("C -> 40%  brightness");
  Serial.println("D -> 60%  brightness");
  Serial.println("E -> 80%  brightness");
  Serial.println("F -> 100% brightness\n");
  
  buttonState = digitalRead(buttonPin);
}

void loop() {
  char brightnessLevel;
  
  lastButtonState = buttonState;
  buttonState = digitalRead(buttonPin);
  
  if(Serial.available() > 0)
  {
    brightnessLevel = Serial.read(); //reads input from serial console
  }

  if(lastButtonState == HIGH && buttonState == LOW) //checks for state change of the button 
  {
      if(!toggle)
      {
        Serial.println("Light Turned On");
  
        switch (previousBrightnessValue) //to turn back on with previous brightness
        {
          case 0:
            Serial.println("New Brightness: 0%\n");
            break;
          case 51:
            Serial.println("New Brightness: 20%\n");
            break;
          case 102:
            Serial.println("New Brightness: 40%\n");
            break;
          case 153:
            Serial.println("New Brightness: 60%\n");
            break;
          case 204:
            Serial.println("New Brightness: 80%\n");
            break;
          case 255:
            Serial.println("New Brightness: 100%\n");
            break;
        }
      }
      else
        Serial.println("\nLight Turned Off\n");
        
      toggle = !toggle;
      brightnessValue = previousBrightnessValue;
  }
  
  if(toggle)
  {
    switch (brightnessLevel) //switch takes char user input and assigns a brightness based on that 
    {
      case 'A':
        brightnessValue = 0;
        Serial.println("New Brightness: 0%");
        previousBrightnessValue = brightnessValue;
        break;
      case 'B':
        brightnessValue = 51;
        Serial.println("New Brightness: 20%");
        previousBrightnessValue = brightnessValue;
        break;
      case 'C':
        brightnessValue = 102;
        Serial.println("New Brightness: 40%");
        previousBrightnessValue = brightnessValue;
        break;
      case 'D':
        brightnessValue = 153;
        Serial.println("New Brightness: 60%");
        previousBrightnessValue = brightnessValue;
        break;
      case 'E':
        brightnessValue = 204;
        Serial.println("New Brightness: 80%");
        previousBrightnessValue = brightnessValue;
        break;
      case 'F':
        brightnessValue = 255;
        Serial.println("New Brightness: 100%");
        previousBrightnessValue = brightnessValue;
        break;
      default:
        break;
    }
  }
  else
  {
    brightnessValue = 0;
  }
  
  analogWrite(pwmPin, brightnessValue);
  delay(1000);
}
