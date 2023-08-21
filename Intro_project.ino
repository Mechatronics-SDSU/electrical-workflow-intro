#define BUTTON_P 13
#define BLUE_LED 9


double percentages[6] = {0, .2, .4, .6, .8, 1};

int current_brightness = 0;
bool on_state = false;
int printed = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(BUTTON_P, INPUT);
  pinMode(BLUE_LED, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  char setting;
  if(digitalRead(BUTTON_P) == LOW)
  {
    if(!on_state)
    {
      Serial.println("ON");
      on_state = true;
      smooth_transition(percentages[0] * 255, percentages[current_brightness] * 255);       
      delay(500);    
    }
    else 
    {
      Serial.println("OFF");
      on_state = false;
      smooth_transition(percentages[current_brightness] * 255, percentages[0] * 255);   
      printed = 0; 
      delay(500);
    }
  }
  else
  {
    if(on_state && printed == 0)
    {
      Serial.println("State key: \n\tA: 0%\n\tB: 20%\n\tC: 40%\n\tD: 60%\n\tE: 80%\n\tF: 100%\n\t?: Current Percentage");
      //Serial.print("Select a state [ex: D]: ");
      printed = 7;
    }
    if(on_state && Serial.available() != 0)
    {
      setting = Serial.read();            
      led_determinate(setting);
      --printed;     
    }    

  }
}

void led_determinate(char setting_state)
{  
  int prev_brightness = current_brightness;
  switch(setting_state)
    {
      case 'A':        
        //write function to do this
        change_brightness(0);
        break;
      case 'B':
        change_brightness(1);
        break;
      case 'C':
        change_brightness(2);
        break;
      case 'D':
        change_brightness(3);
        break;
      case 'E':
        change_brightness(4);
        break;
      case 'F':
        change_brightness(5);
        break;          
      case '?':
        //Serial.println(dec);
        Serial.print("Current setting: ");
        Serial.print(percent_calc(percentages[current_brightness]));
        Serial.println("% ");
        break;
      default:
        Serial.println("Whoops - invalid input!");
        break;
    }

    if(setting_state >= 'A' && setting_state <= 'F')
    {
      smooth_transition(percentages[prev_brightness] * 255, percentages[current_brightness] * 255);
    }
}

int percent_calc(double percent)
{
  double percentage = percent * 100;
  return (int)percentage;
}

void change_brightness(int state)
{
  Serial.print("New Brightness: ");
  Serial.print(percent_calc(percentages[state]));
  Serial.println("% ");
  current_brightness = state;
}

void smooth_transition(int sett_1, int sett_2)
//setting 1 to setting 2
{
  if(sett_1 < sett_2)
  {
    for(int i = sett_1; i <= sett_2; ++i)
    {
      analogWrite(BLUE_LED, i);
      delay(25);
    }
  }
  else if(sett_1 > sett_2)
  {
    for(int i = sett_1; i >= sett_2; --i)
    {
      analogWrite(BLUE_LED, i);
      delay(25);
    }
  }
}
