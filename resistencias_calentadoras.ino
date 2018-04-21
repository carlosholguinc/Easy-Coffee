
bool band=0;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}

// Funcion para activar y desactivar las resistencias calentadoras
bool encender_res(float valDeseado, float valEntrada)
{
  if(valEntrada == valDeseado) band = 1;
  if(valEntrada == valDeseado-5.0) band = 0;
  
  if(valEntrada < valDeseado and band = 0) return HIGH;
  else return LOW;
}

