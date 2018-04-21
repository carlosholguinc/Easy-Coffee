#include <Servo.h>
char blueToothVal;
float duration, distance;

int pinServo= 13;

Servo servo;
void setup()
{
 servo.attach(pinServo);
 pinMode(A5, OUTPUT); // trig pin
 pinMode(A4, INPUT); // echo pin
 Serial.begin(9600);

  delay(3000);
}
 
 
void loop()
{

  // Output pulse with 1ms width on trigPin
  digitalWrite(A5, HIGH);
  delay(1);
  digitalWrite(A5, LOW);
  
  // Measure the pulse input in echo pin
  duration = pulseIn(A4, HIGH);
  // Distance is half the duration devided by 29.1 (from datasheet)
  distance = (duration/2) / 29.1;
  // if distance less than 0.5 meter and more than 0 (0 or less means over range)
  Serial.println("2");
  
  if(Serial.available())
  {
    blueToothVal=Serial.read();
    Serial.println(blueToothVal);
  }

  
}
