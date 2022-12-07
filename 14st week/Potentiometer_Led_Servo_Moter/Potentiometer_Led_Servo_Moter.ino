#include <Servo.h>

#define MINANALOG 0
#define MAXANALOG 1023
#define MINPIN 0
#define MAXPIN 255
#define MINANGLE 0
#define MAXANGLE 180
#define TOTAL_PIN 6
#define LED_PIN 4
#define NUMBER_OF_BLINK 2

int Pin[TOTAL_PIN] = {2,3,4,5,6,7};  //Array of pin
int *pPin = Pin;  //Pointer of pin
int nPotenPin = A0;
int nAngle = 90;  //Half an angle
int i = 0;

Servo myServo;  //Variable declaration: myServo

void LedBlink(int nDelay) //Function of led blink type 1
{
  for(i = 0; i < NUMBER_OF_BLINK; i++)  //Repeat twice
  {
  digitalWrite(pPin[i], HIGH);  // Led on
  Serial.print("Led: ON\n");
  delay(nDelay); // Wait for nDelay
  
  digitalWrite(pPin[i], LOW); // Led off
  Serial.print("Led: OFF\n");
  delay(nDelay); // Wait for nDelay
  }
}

void LedBlink2(int nDelay)  //Function of led blink type 2
{
  for(i = 0; i < NUMBER_OF_BLINK; i++)  //Repeat twice
  {
  digitalWrite(pPin[i+2], HIGH);  // Led on
  Serial.print("Led: ON\n");
  delay(nDelay); // Wait for nDelay
  
  digitalWrite(pPin[i+2], LOW); // Led off
  Serial.print("Led: OFF\n");
  delay(nDelay); // Wait for nDelay
  }
}

void LedOff() //Function: Led off
{
  for(i = 0; i < LED_PIN; i++)
  {
  digitalWrite(pPin[i], LOW); //Led off
  }
}

void setup()
{
  for(i = 0; i < LED_PIN; i++)
  {
    pinMode(pPin[i], OUTPUT); //Connect pin 1~4
  }
  pinMode(pPin[4], INPUT);  //Connect pin 5
  myServo.attach(pPin[5]);  //Connect pin 6 the servo
  
  Serial.begin(9600);
}
void loop()
{
  int nValue = analogRead(nPotenPin); //Read analog value of nPotenpin
  int nAngleValue = map(nValue, MINANALOG, MAXANALOG, MINANGLE, MAXANGLE);
  //Store the converted value to angle value
  int nDelay = map(nValue, MINANALOG, MAXANALOG, MINPIN, MAXPIN);
  //Store the converted value to delay value  

  if(digitalRead(pPin[4]) == HIGH) // if switch on
  {
  Serial.print("Switch: ON\n");
  
  myServo.write(nAngle);  //Rotate by angle

  if(nAngleValue <= nAngle) //if nAngleValue =< 90
    {
      LedBlink(nDelay); //Blink type 1
    } 
   else //else
    {
      LedBlink2(nDelay);  //Blink type 2
    }
  }
  else
  {
   Serial.print("\nSwitch:OFF\n"); 
   LedOff;  //Led off
     myServo.write(0);  //Rotate by angle "0"
  }
}
