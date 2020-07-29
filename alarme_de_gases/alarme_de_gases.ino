#define ledeVerde 2
#define lampada 6
#define entradaDigital 13
#define  entradaAnalogica 0
#define espera 1000

bool dSensor;
int aSensor;

void setup() {

  Serial.begin(9600);
  pinMode(entradaDigital, INPUT);
 
  pinMode(ledeVerde, OUTPUT);
  
  
  pinMode(lampada, OUTPUT);
  digitalWrite(lampada, HIGH ); 

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

  if (aSensor < 100)
  {
   digitalWrite(ledeVerde, HIGH);
  }
  else
  {
    digitalWrite(ledeVerde, LOW);
  }
  
 
   if (aSensor >= 110)
  {
   digitalWrite(lampada, LOW );
  }
  else
  {
     digitalWrite(lampada, HIGH );
  }
}
