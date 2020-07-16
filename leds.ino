
#define ledeVermelho 2
#define espera 1000


void setup() {

  pinMode(ledeVermelho, OUTPUT);

}

void loop() {
  digitalWrite(ledeVermelho, HIGH);
  delay(espera);
  digitalWrite(ledeVermelho, LOW);
  delay(espera);
}
