#define LED_PIN 5
#define BUTTON_PIN 4

int brightness = 0;
int ledState = 0;
int lastButtonState;
int currentButtonState;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  Serial.begin(9600);
  
  currentButtonState = digitalRead(BUTTON_PIN); //Read current button state
}

void loop() {
  lastButtonState = currentButtonState; //Save last state
  currentButtonState = digitalRead(BUTTON_PIN); //Read new state
  
  if (lastButtonState == HIGH && currentButtonState == LOW){ //If button has been pressed
    if (ledState == 0){ //If led was off
     ledState = brightness; //Set led to brightness
     analogWrite(LED_PIN, ledState);
    }
    else if (ledState != 0){ //If led was on
     ledState = 0; //Set led to off
     analogWrite(LED_PIN, ledState);
    }
  }

  char input = Serial.read();
  
  switch (input) {
    case 'A':
      brightness = 0;
      if (ledState != 0){
       analogWrite(LED_PIN, brightness);
      }
      Serial.println("New Brightness: 0%");
      break;
    case 'B':
      brightness = 255*0.2;
      if (ledState != 0){
      analogWrite(LED_PIN, brightness);
      }
      Serial.println("New Brightness: 20%");
      break;
    case 'C':
      brightness = 255*0.4;
      if (ledState != 0){
      analogWrite(LED_PIN, brightness);
      }
      Serial.println("New Brightness: 40%");
      break;
    case 'D':
      brightness = 255*0.6;
      if (ledState != 0){
      analogWrite(LED_PIN, brightness);
      }
      Serial.println("New Brightness: 60%");
      break;
    case 'E':
      brightness = 255*0.8;
      if (ledState != 0){
      analogWrite(LED_PIN, brightness);
      }
      Serial.println("New Brightness: 80%");
      break;
    case 'F':
      brightness = 255;
      if (ledState != 0){
      analogWrite(LED_PIN, brightness);
      }
      Serial.println("New Brightness: 100%");
      break;
    case '?':
      Serial.print("Current Brightness: ");
      int bp = (brightness/255.0)*100;
      Serial.print(bp);
      Serial.println("%");
      break;
  }
}
