#include <Servo.h>
String mensaje;
float duration, nivel;

int pinServo= 4;
char estado = 'A';
char pEstado = 0;
int vaso = 0;
int pinVaso = 2;
bool valvula = false;
bool bandTemp=0;
int pinCalentador = 4;

const int analogInPin = A0;  // Entrada analogica para el sensor de temperatura

float tempc = 0;        // value read from the pot
float sensorValue = 0;

const byte interruptPin = 2;


Servo servo;
void setup()
{
 servo.attach(pinServo);
 pinMode(A5, OUTPUT); // trig pin
 pinMode(A4, INPUT); // echo pin
 Serial.begin(9600);

  delay(3000);

  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), monitorVaso, CHANGE);
}
 
void loop()
{
  readWaterLevel();

  if(Serial.available())
  {
      mensaje=Serial.readString();
  }

  if(mensaje.equals("init") && vaso == 1 && nivel > 10.0){
    pEstado = 1;
    estado = 'B'; 
    
   }
   else{
      pEstado = 0;
      estado = 'A';

    }

  Serial.println(mensaje);
  
  switch(estado){
    
   case 'A': 
          turnOffAll();           // apaga todo

          break; 
   case 'B': 
          startAll();
          digitalWrite(pinCalentador, encender_res(29,tempc = temperatura()));
          Serial.println("Estado: B");
          break;
     default: break;
   }


   
   Serial.println("Vaso:"+String(vaso));
   Serial.println("Estado:"+String(estado));
   Serial.println("Agua:"+String(nivel));

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
    digitalWrite(pinCalentador, LOW);
  }

void startAll(void){
   servo.write(45);
    digitalWrite(pinCalentador, HIGH);
  }

  
bool encender_res(float valDeseado, float valEntrada)
{
  if(valEntrada == valDeseado) bandTemp = 1;
  if(valEntrada == valDeseado-5.0) bandTemp = 0;
  
  if(valEntrada < valDeseado && bandTemp == 0) return HIGH;
  else return LOW;
}

float temperatura (void)
{
  // lee valor analogico
  sensorValue = analogRead(analogInPin);
  
  // conversion a temperatura
  tempc = sensorValue * 5.0 * 100.0 / 1024.0;

  //Tiempo de espera para leer adc
  delay(2);
  Serial.println("Temperatura: "+ String(tempc));
  return tempc;
}

void monitorVaso(){
    vaso = digitalRead(pinVaso);
  }
