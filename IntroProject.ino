

int buttonValue = 0;
int button = 7;
int LED = 6;
byte lastButtonState;
byte ledState = LOW;

unsigned long lastTimeButtonStateChanged = millis();
unsigned long debounceDuration = 50;


void setup() {
  Serial.begin(9600);
  while (! Serial);
  Serial.println("Enter a valid command ");
  
  pinMode(button, INPUT);
  pinMode(LED, OUTPUT);
  //lastButtonState = digitalRead(button);
}

void loop() {
   
            if(Serial.available()){
              char ch = Serial.read();
           switch (ch) {
              case 'A' :
                   while (ch = 'A') {
                        if (millis() - lastTimeButtonStateChanged >= debounceDuration){
                         byte buttonState = digitalRead(button);
                            if (buttonState != lastButtonState) {
                              lastTimeButtonStateChanged = millis();
                              lastButtonState = buttonState;
                              if(buttonState == LOW) {
                                     if (ledState != LOW) {
                                       ledState = LOW;
                    
                                        digitalWrite(LED, ledState );
                                        delay(20);
                                      }
                                     else{
                                      ledState = LOW;
                    
                                            digitalWrite(LED, ledState);
                                            delay(20);
                                     }
                                      
                                      }
                                    
                                }
                              
                              } 
                           }
                   Serial.print("Brightness:  0%\n");
                   break;

              case 'B' :
                   while (ch = 'B') {
                        if (millis() - lastTimeButtonStateChanged >= debounceDuration){
                         byte buttonState = digitalRead(button);
                            if (buttonState != lastButtonState) {
                              lastTimeButtonStateChanged = millis();
                              lastButtonState = buttonState;
                              if(buttonState == LOW) {
                                     if (ledState != LOW) {
                                       for( ledState = 51; ledState >= 0; ledState -=1)
                    
                                        analogWrite(LED, ledState );
                                        delay(20);
                                      }
                                     else{
                                      for( ledState = 0; ledState <= 51; ledState +=1)
                    
                                            analogWrite(LED, ledState);
                                            delay(20);
                                     }
                                      
                                      }
                                    
                                }
                              
                              } 
                           }
                           Serial.print("Brightness:  20\n");
                    break;
              case 'C' :
                   while (ch = 'C') {
                        if (millis() - lastTimeButtonStateChanged >= debounceDuration){
                         byte buttonState = digitalRead(button);
                            if (buttonState != lastButtonState) {
                              lastTimeButtonStateChanged = millis();
                              lastButtonState = buttonState;
                              if(buttonState == LOW) {
                                     if (ledState != LOW) {
                                       for( ledState = 102; ledState >= 0; ledState -=1)
                    
                                        analogWrite(LED, ledState );
                                        delay(20);
                                      }
                                     else{
                                      for( ledState = 0; ledState <= 102; ledState +=1)
                    
                                            analogWrite(LED, ledState);
                                            delay(20);
                                     }
                                      
                                      }
                                    
                                }
                              
                              } 
                           }
                           Serial.print("Brightness:  40\n");
                    break;
              case 'D' :
                   //for(int ledState = 0; ledState <= 153; ledState +=1)
                    
                    //analogWrite(LED, ledState);
                    //delay(20);
                   
                      while (ch = 'D') {
                        if (millis() - lastTimeButtonStateChanged >= debounceDuration){
                         byte buttonState = digitalRead(button);
                            if (buttonState != lastButtonState) {
                              lastTimeButtonStateChanged = millis();
                              lastButtonState = buttonState;
                              if(buttonState == LOW) {
                                     if (ledState != LOW) {
                                       for( ledState = 153; ledState >= 0; ledState -=1)
                    
                                        analogWrite(LED, ledState );
                                        delay(20);
                                      }
                                     else{
                                      for( ledState = 0; ledState <= 153; ledState +=1)
                    
                                            analogWrite(LED, ledState);
                                            delay(20);
                                     }
                                      
                                      }
                                    
                                }
                              
                              } 
                           }
                          
                        Serial.print("Brightness:  60%\n");
                    break;
              case 'E' :
                   while (ch = 'E') {
                        if (millis() - lastTimeButtonStateChanged >= debounceDuration){
                         byte buttonState = digitalRead(button);
                            if (buttonState != lastButtonState) {
                              lastTimeButtonStateChanged = millis();
                              lastButtonState = buttonState;
                              if(buttonState == LOW) {
                                     if (ledState != LOW) {
                                       for( ledState = 204; ledState >= 0; ledState -=1)
                    
                                        analogWrite(LED, ledState );
                                        delay(20);
                                      }
                                     else{
                                      for( ledState = 0; ledState <= 204; ledState +=1)
                    
                                            analogWrite(LED, ledState);
                                            delay(20);
                                     }
                                      
                                      }
                                    
                                }
                              
                              } 
                           }
                           Serial.print("Brightness:  80%\n");
                    break;
              case 'F' :
                   while (ch = 'F') {
                        if (millis() - lastTimeButtonStateChanged >= debounceDuration){
                         byte buttonState = digitalRead(button);
                            if (buttonState != lastButtonState) {
                              lastTimeButtonStateChanged = millis();
                              lastButtonState = buttonState;
                              if(buttonState == LOW) {
                                     if (ledState != LOW) {
                                       for( ledState = 255; ledState >= 0; ledState -=1)
                    
                                        analogWrite(LED, ledState );
                                        delay(20);
                                      }
                                     else{
                                      for( ledState = 0; ledState <= 255; ledState +=1)
                    
                                            analogWrite(LED, ledState);
                                            delay(20);
                                     }
                                      
                                      }
                                    
                                }
                              
                              } 
                           }
                           Serial.print("Brightness:  100%\n");
                    break;
            }
          }
}


         
