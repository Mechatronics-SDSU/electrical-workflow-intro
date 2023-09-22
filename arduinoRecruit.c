// C++ code
//
bool lit = false;
int percent=0;
void setup()
{
  pinMode(3, OUTPUT);
  pinMode(11, INPUT);
  Serial.begin(9600);
}

void loop(){
  getInput();
  buttonInput();
  
}

void buttonInput(){
  int buttonState = digitalRead(11);
  
  if (buttonState == HIGH){
    lit = !lit;
    delay(500);
    if(lit)
      analogWrite(3, 255*percent/100);
    else
      analogWrite(3, 0);
  }
}

void getInput(){
  if (Serial.available() > 0) {
    
    char menuChoice = Serial.read();
    Serial.println(menuChoice);
    
    switch (menuChoice) {
      case 'A':
      case 'a':
        percent = 0;
        analogWrite(3,255*0.0);
        lit = true;
        break;
  
      case 'B':
      case 'b':
        percent = 20;
        analogWrite(3,255*0.2);
        lit = true;
        break;
  
      case 'C':
      case 'c':
        percent = 40;
        analogWrite(3,255*0.4);
        lit = true;
        break;
      
      case 'D':
      case 'd':
        percent = 60;
        analogWrite(3,255*0.6);
        lit = true;
        break;
      
      case 'E':
      case 'e':
        percent = 80;
        analogWrite(3,255*0.8);
        lit = true;
        break;
      
      case 'F':
      case 'f':
        percent = 100;
        analogWrite(3,255*1.0);
        lit = true;
        break;
  
      case '?':
        Serial.println("Led Brightness is " + String(percent) + "%");
        break;
      
      default:
        Serial.println("Please choose a valid selection");
    }
    delay(500);
  }
}