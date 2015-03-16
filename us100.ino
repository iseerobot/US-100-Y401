/*
* Code sudah diuji dan ditest oleh iseerobot.com
*  - TIM QC iseerobot -
*/

//Wiring : 
// VCC = 5V
// GND = GND
// Trigger = PIN digital 6
// Echo = PIN digital 7
//NOTE: Jangan lupa untuk meLEPAS jumper di US-100

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
  
  //Tangkap sinyal pantulan dan konversi ke dalam cm
  distance = pulseIn(echo, HIGH);
  distance = distance*0.0001657;
  //kirim hasil lewat usart
  Serial.println(distance);
  delay(50);
}