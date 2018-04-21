#include <Servo.h>
String mensaje;
float duration, nivel;
int pinServo= 2;
String estado = "idle";
bool vaso = false;
bool valvula = false;
bool bandTemp=0;
int pinCalentador;


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
  readWaterLevel();

  if(Serial.available())
  {
      mensaje=Serial.readString();
  }


  
  switch(estado){
    
   case idle: 
          turnOffAll();
          break; 
   case start: 
          startAll();
          break;

    
   }
  
}

void readWaterLevel(void){

   // Output pulse with 1ms width on trigPin
  digitalWrite(A5, HIGH);
  delay(1);
  digitalWrite(A5, LOW);
  
  // Measure the pulse input in echo pin
  duration = pulseIn(A4, HIGH);
  // Distance is half the duration devided by 29.1 (from datasheet)
  nivel = (duration/2) / 29.1;
  // if distance less than 0.5 meter and more than 0 (0 or less means over range)
  
}

void turnOffAll(void){
    servo.write(0);
    digitalWrite(calentar, LOW);
  }

void startAll(void){
  servo.write(45);
    digitalWrite(pinCalentador, HIGH);
  }

  
bool encender_res(float valDeseado, float valEntrada)
{
  if(valEntrada == valDeseado) bandTemp = 1;
  if(valEntrada == valDeseado-5.0) bandTemp = 0;
  
  if(valEntrada < valDeseado and bandTemp = 0) return HIGH;
  else return LOW;
}
