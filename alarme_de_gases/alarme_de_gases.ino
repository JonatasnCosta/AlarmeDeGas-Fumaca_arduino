#define ledeVerde 2
#define ledeVermelho 3
#define entradaDigital 4
#define  entradaAnalogica 0
#define espera 1000

bool dSensor;
int aSensor;

void setup() {

  Serial.begin(9600);
  pinMode(entradaDigital, INPUT);
 
  pinMode(ledeVerde, OUTPUT);
  
  
  pinMode(ledeVermelho, OUTPUT);
  digitalWrite(ledeVermelho, LOW); 

}

void loop() {
  
  dSensor = digitalRead (entradaDigital);
  aSensor = analogRead (entradaAnalogica);

  Serial.print("Leitura entrada digital:");
  Serial.println(dSensor);

  Serial.print("Nível do Gás:");
  Serial.println(aSensor);
  Serial.println();
  delay(1000);

  if (aSensor < 500)
  {
   digitalWrite(ledeVerde, HIGH);
  }
  else
  {
     digitalWrite(ledeVerde, LOW);
  }

   if (aSensor >= 500)
  {
   digitalWrite(ledeVermelho, HIGH);
  }
  else
  {
     digitalWrite(ledeVermelho, LOW);
  }
}
