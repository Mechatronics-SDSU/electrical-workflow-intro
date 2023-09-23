// C++ code
//
int buttonNew;
int buttonOld = 1;
int LedState = 0;

void setup()
{ 
     	
  Serial.begin(9600);
  Serial.println("New Test");
  pinMode(3, OUTPUT);
  pinMode(4, INPUT);
}

void loop()
{

 
  
  while(buttonOld==1)
  {
	buttonOld= digitalRead(4);
  }
  
	analogWrite(3,255*(LedState/100));
  
  while (buttonOld == 0)
  {
	delay(1000);
    while(Serial.available()==0){
      if(digitalRead(4)==0)
      {
        buttonOld=1;
        break;
      }
 }
    delay(1000);
	if(buttonOld==1)
    {
   	  analogWrite(3,0);
      break;
    }
    
     String LedLight = Serial.readString();  
  if(LedLight == "A")
  {
    LedState = 0;
    analogWrite(3,0);
    Serial.println("New Brightness: 0%");
  }
  else if(LedLight == "B")
  {
    LedState = 20;
    analogWrite(3,51);
    Serial.println("New Brightness: 20%");
  }
    else if(LedLight == "C")
  {
      LedState = 40;
      analogWrite(3,102);
    Serial.println("New Brightness: 40%");
  }
  else if(LedLight == "D")
  {
    LedState = 60;
    analogWrite(3,153);
    Serial.println("New Brightness: 60%");
  }
    else if(LedLight == "E")
  {
		LedState = 80;
      analogWrite(3,204);
    Serial.println("New Brightness: 80%");
  }
   else if(LedLight == "F")
  {
      LedState = 100;
     analogWrite(3,255);
    Serial.println("New Brightness: 100%");
  }
  else if(LedLight == "?")
  {
   
  Serial.print("Current Brightness is %");
  Serial.println(LedState);  
  }
  else
  {
    Serial.println("Input a valid letter that is between A-F");
  }
  
  }
  
 
}
