#define MAXANALOG 1023.0  //Maximum size of analog
#define MAXVOLT 5.0     //Maximum size of volt
#define TOTAL_PIN 8   //Number of total pins
#define OUTPUT_PIN 6    //Number of output pins(LED,vibration)
#define TOTAL_SWITCH 2  //Number of total switch pins 

#define SAFE_TOUCH 40   //Safe temperature for touching
#define WARNING_TOUCH 45  //Warning temperature for touching
#define DANGER_TOUCH 55   //Dangerous temperautre for touching
#define SAFE_EAT 55   //Safe temperature for eating
#define DANGER_EAT 60 //Dangerous temperautre for eating
#define LOW_BURN_TIME 3600000 //The time(3600s) of low temperature burn
#define HIGH_BURN_TIME 10000  //The time(10s) of High temperature burn

typedef struct  //Structure of Pins
{
  int Pin[TOTAL_PIN] = {2,3,4,5,6,7,8,9}; //Array of pins
  int *pPin = Pin;  //Pointer of Pin
  int TempPin = A0; //Temperature sensor pin
}Pins;

typedef struct  //Structure of etc values
{
  float Temperature = 0;  //Value of temperature
  float Voltage = 0;  //Value of voltage
  int Value = 0;    //Value to read
  int nDelay = 200; //Blink delay
}Values;

Pins type;  //defined as type
Values etc; //defined as etc

int i = 0;  //Temporary variable

void Led_On(int *pPin, int num) //Function: LED on
{
  if(num > TOTAL_SWITCH)  //If the LED pins
  {
    digitalWrite(pPin[num-1], LOW); //Off the LED that was on
    digitalWrite(pPin[num], HIGH);  //New LED on
  }
  else
  {
    digitalWrite(pPin[num], HIGH);  //New LED on
  }
}

void Vibration(int *pPin, int Danger_time)  
{  //Function: Vibration notification
  
  unsigned long time = millis(); //Get the time in millis

  if(time > Danger_time) 
  {
  digitalWrite(pPin[5], HIGH);  //Vibration motor on
  }
}

void Type1_Eating(int *pPin) //Function: Type 1->for eating
{
  Serial.print("Type 1: ON\n");
  digitalWrite(pPin[0], HIGH);  //Type 1 LED(blue) on
      
  if(etc.Temperature < SAFE_EAT) //Safe range
  {
    Led_On(pPin, 2); //LED(green) on
  }
  else if(etc.Temperature < DANGER_EAT)//Warning range
  {
    Led_On(pPin, 3); //LED(yellow) on
  }
  else  //Danger range
  {
    Led_On(pPin, 4); //LED(red) on
  }
}

void Type2_Touching(int *pPin) //Function: Type 2->for drinking
{
  Serial.print("Type 2: ON\n");
      
  digitalWrite(pPin[0], LOW); //Type 1 LED off
  digitalWrite(pPin[1], HIGH);  //Type 2 LED on
      
  if(etc.Temperature < SAFE_TOUCH) //Safe range
  {
    Led_On(pPin, 2); //LED(green) on
  }
  else if(etc.Temperature < WARNING_TOUCH) 
    //Low-temperature burn risk zone
  {
    Led_On(pPin, 3); //LED(yellow) on
    Vibration(pPin, LOW_BURN_TIME); //Low-temperature burn risk zone
  }
  else if(etc.Temperature < DANGER_TOUCH) //2nd degree burn risk zone
  {
    Led_On(pPin, 3);
    delay(etc.nDelay);
    digitalWrite(pPin[3], LOW); //The LED(yellow) is blinking
    delay(etc.nDelay);
    Vibration(pPin, HIGH_BURN_TIME); //Vibration starts after 10 seconds
  }
  else  //High-temperature burn risk zone
  {
    Led_On(pPin, 4); //LED(red) on
    Vibration(pPin, 0); //Vibration starts after 0 seconds
  }
}

void setup()
{
 for(i = 0; i < OUTPUT_PIN; i++)
  {
    pinMode(type.pPin[i], OUTPUT);  //Connect LED pins
  }
   for(i = OUTPUT_PIN; i < TOTAL_PIN; i++)
  {
    pinMode(type.pPin[i], INPUT); //Connect Switch pins
  }
  
  Serial.begin(9600);
}

void loop()
{
  etc.Value = analogRead(type.TempPin); 
  //Temperature's analog volt value
  etc.Voltage = (etc.Value)*MAXVOLT/MAXANALOG; //Change vlaue to volt
  etc.Temperature = (etc.Voltage)*100-50; 
  //Calculate voltage to temperature of celcious

  if(digitalRead(type.pPin[6]) == HIGH) //If switch on
  {
    Serial.print("Switch: ON\n");
    Serial.print("Temperature: ");
    Serial.println(etc.Temperature);
    
    if(digitalRead(type.pPin[7]) == HIGH) 
    //If swich2 on(type 1): eat or drink
    {
      Type1_Eating(type.pPin);
    }
    else  //else(type 2): touch
    {
      Type2_Touching(type.pPin);
    }
  }
  else  //Exit
  {
    Serial.print("Switch: OFF\n\n"); 
    
    for(i = 0; i < TOTAL_PIN; i++)
    {
      digitalWrite(type.pPin[i], LOW);  //All LED off
    }
  }
}
