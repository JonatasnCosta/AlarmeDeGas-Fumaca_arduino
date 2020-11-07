// INCLUSÃO DE BIBLIOTECAS
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// INCLUSÃO DE BIBLIOTECAS
#define sirene 6
#define entradaDigital 8
#define entradaAnalogica 0
#define espera 1000
#define endereco  0x3F // Endereços comuns: 0x27, 0x3F
#define colunas  16
#define linhas   2

bool dSensor;
int aSensor;

// INSTANCIANDO OBJETOS
LiquidCrystal_I2C lcd(endereco, colunas, linhas);

void setup() {
  lcd.init(); // INICIA A COMUNICAÇÃO COM O DISPLAY
  lcd.backlight(); // LIGA A ILUMINAÇÃO DO DISPLAY
  lcd.clear(); // LIMPA O DISPLAY

  lcd.print("Iniciando ...");
  delay(5000); // DELAY DE 5 SEGUNDOS
  lcd.setCursor(0, 1); // POSICIONA O CURSOR NA PRIMEIRA COLUNA DA LINHA 2
  lcd.print("Sensor de Gas");
  delay(5000); // DELAY DE 5 SEGUNDOS
  
  lcd.noBacklight(); // DESLIGA A ILUMINAÇÃO DO DISPLAY
  delay(2000); // DELAY DE 2 SEGUNDOS
  lcd.backlight(); // LIGA A ILUMINAÇÃO DO DISPLAY
  delay(2000); // DELAY DE 2 SEGUNDOS
  
  lcd.clear(); // LIMPA O DISPLAY
  //lcd.noBacklight(); // DESLIGA A ILUMINAÇÃO DO DISPLAY
  Serial.begin(9600);
  pinMode(entradaDigital, INPUT);
  pinMode(sirene, OUTPUT);
  digitalWrite(sirene, HIGH ); 

}

void loop() {
  
  dSensor = digitalRead (entradaDigital);
  aSensor = analogRead (entradaAnalogica);


  
   if (aSensor >= 100)
  {
   digitalWrite(sirene, LOW );
  }
  else
  {
    digitalWrite(sirene, HIGH );
  }
  lcd.print("Nivel do Gas:");
  lcd.setCursor(0,1); // POSICIONA O CURSOR NA PRIMEIRA COLUNA DA LINHA 2
  lcd.print(aSensor);
  lcd.setCursor(0,2);
  delay(1000);
  lcd.clear();
 
}
