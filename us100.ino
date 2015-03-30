/*
* This code is tested by iseerobot.com
* -QC iseerobot -
*/

//Wiring : 
// VCC = 5V
// GND = GND
// Trigger = PIN digital 6
// Echo = PIN digital 7
//NOTE: don't forget to pull jumper on US-100

const int trigger = 6;
const int echo = 7;
float distance;
 
void setup(){
  Serial.begin(9600);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
}
void loop(){
  //Trigger US-100
  digitalWrite(trigger, LOW);
  delayMicroseconds(5);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  
  //Convert echo sound to cm
  distance = pulseIn(echo, HIGH);
  distance = distance*0.0001657;
  
  //Send range via USART
  Serial.println(distance);
  delay(50);
}