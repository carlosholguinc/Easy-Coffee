char blueToothVal;

void setup()
{
 Serial.begin(9600);

  delay(1000);
}

void loop()
{
  
  if(Serial.available())
  {
    blueToothVal=Serial.read();
    //Serial.println(blueToothVal);
  }
  delay(1000);
  
}
