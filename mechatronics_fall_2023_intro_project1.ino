// C++ code
//

const int LED_PIN       = 3;
const int BUTTON_PIN    = 4;
const int LED_LOW       = 10;
int       ledState      = 0;
int       ledBrightness = 100;
int       brightnessPercent;
int 	  printBrightness;
char      userInput;

void setup()
{
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  
}

void loop()
{
  //Serial.println(digitalRead(BUTTON_PIN));
  //Check is button is pressed, check ledState
  if(digitalRead(BUTTON_PIN) == LOW && ledState == 0) {
  	digitalWrite(LED_PIN, HIGH);
    delay(20);
    ledState = 1;
    //Changing Brightness
    while (digitalRead(BUTTON_PIN) != LOW) {
    	userInput = Serial.read();
    	switch (userInput) {
   		    case 'A':
    	    case 'a':
        		ledBrightness = 0;
      			analogWrite(LED_PIN, ledBrightness);
      			brightnessPercent = (ledBrightness * 100) / 255;
      			Serial.print("New Brightness: ");
       	    	Serial.print(printBrightness, DEC);
      			Serial.println("%");
      			break;
     	    case 'B':
     	    case 'b':
      			ledBrightness = 51;
      			analogWrite(LED_PIN, ledBrightness);
      			printBrightness = (ledBrightness * 100) / 255;
       			Serial.print("New Brightness: " + printBrightness);
      			Serial.println("%");
      			break;
    		case 'C':
     		case 'c':
      			ledBrightness = 102;
      			analogWrite(LED_PIN, ledBrightness);
      			printBrightness = (ledBrightness * 100) / 255;
      			Serial.print("New Brightness: ");
      	    	Serial.print(printBrightness, DEC);
      			Serial.println("%");
      	    	break;
     		case 'D':
     		case 'd':
      			ledBrightness = 153;
      			analogWrite(LED_PIN, ledBrightness);
      			printBrightness = (ledBrightness * 100) / 255;
      			Serial.print("New Brightness: ");
     	    	Serial.print(printBrightness, DEC);
     	 		Serial.println("%");
     	 		break;
        	case 'E':
        	case 'e':
      			ledBrightness = 204;
      			analogWrite(LED_PIN, ledBrightness);
      			printBrightness = (ledBrightness * 100) / 255;
      			Serial.print("New Brightness: ");
       	    	Serial.print(printBrightness, DEC);
      			Serial.println("%");
      	    	break;
      		case 'F':
     		case 'f':
      			ledBrightness = 255;
      			analogWrite(LED_PIN, ledBrightness);
      			printBrightness = (ledBrightness * 100) / 255;
      			Serial.print("New Brightness: ");
        		Serial.print(printBrightness, DEC);
      			Serial.println("%");
      			break;
      		case '?':
      			Serial.print("Current Brightness: ");
        		Serial.print(printBrightness, DEC);
      			Serial.println("%");
      		default:
      			break;
        }
    }
  }
  else if (digitalRead(BUTTON_PIN) == LOW && ledState == 1) {
 	digitalWrite(LED_PIN, LOW);
    delay(20);
    ledState = 0;
  }
}