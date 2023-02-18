const int outputPin = 9;
int count =0;
int state =1;
int lastState = 1;
static char userInput = 'F';
int brightness=0;
bool check = false;





void setup() {
  Serial.begin(9600);
  pinMode(outputPin, OUTPUT);
  pinMode(A1, INPUT);

}

void loop() {
state = digitalRead(A1);
if(state == 1){
  count++;
}
if(Serial.available() > 0){
  userInput = Serial.read();
  check = true;

}

if(count % 2 == 0){
  digitalWrite(outputPin, HIGH);
 
  switch(userInput){
    case'F':
    analogWrite(outputPin, 255);
    brightness = 100;
    break;

    case'E':
    analogWrite(outputPin,(0.8*255));
        brightness = 80;
    break;

    case'D':
    analogWrite(outputPin,(0.6*255));
        brightness = 60;
    break;

    case'C':
    analogWrite(outputPin, (0.4*255));
        brightness = 40;
    break;

    case'B':;
    analogWrite(outputPin, (0.2*255));
        brightness = 20;
       
    break;

    case'A':
    analogWrite(outputPin, 0);
        brightness = 0;
         
    break;


  }


}
else{digitalWrite(outputPin, LOW);
}
if(check){
 Serial.print("Brightness:");
  Serial.println(brightness);
  Serial.print("%\n");
  check = false;
}



delay(125);





}
