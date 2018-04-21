const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to

float tempc = 0;        // value read from the pot
float sensorValue = 0;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}

float temperatura ()
{
  // lee valor analogico
  sensorValue = analogRead(analogInPin);
  
  // conversion a temperatura
  tempc = sensorValue * 5.0 * 100.0 / 1024.0;

  //Tiempo de espera para leer adc
  delay(2);
  return tempc;
}

