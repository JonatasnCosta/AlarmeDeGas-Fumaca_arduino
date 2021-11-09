// INCLUSÃO DE BIBLIOTECAS
#include <Wire.h>
#include <LiquidCrystal_I2C.h>


#define sirene 6
#define entradaDigital 8
#define entradaAnalogica 0
#define endereco 0x3F // Endereços comuns: 0x27, 0x3F
#define colunas 16
#define linhas 2
#define botao 3
// DEFINIÇÃO DAS CONSTANTES
//Outro codigooo

bool dSensor;
int aSensor;

// INSTANCIANDO OBJETOS
LiquidCrystal_I2C lcd(endereco, colunas, linhas);

void setup()
{
  lcd.init();      // INICIA A COMUNICAÇÃO COM O DISPLAY
  lcd.backlight(); // LIGA A ILUMINAÇÃO DO DISPLAY
  lcd.clear();     // LIMPA O DISPLAY

  lcd.print("  Iniciando ...");
  lcd.setCursor(0, 1);
  delay(5000);// DELAY DE 5 SEGUNDOS
  lcd.clear();
  lcd.print("Checando os ");
  lcd.setCursor(0, 1);
  lcd.print("componentes");
  lcd.setCursor(0, 2);
  delay(2000);
  lcd.clear();
  delay(2000);
  lcd.print("   Sistema ok");
  lcd.setCursor(0, 1);
  delay(2000); 
  lcd.print("Sensor de gas");
  lcd.setCursor(0, 1); // POSICIONA O CURSOR NA PRIMEIRA COLUNA DA LINHA 1
  delay(2000); // DELAY DE 5 SEGUNDOS

  lcd.clear(); // LIMPA O DISPLAY
  Serial.begin(9600);
  pinMode(entradaDigital, INPUT);
  pinMode(sirene, OUTPUT);
  digitalWrite(sirene, HIGH);
  pinMode(botao, INPUT_PULLUP);
  
}

void loop()
{
  dSensor = digitalRead(entradaDigital);
  aSensor = analogRead(entradaAnalogica); // VERIFICA O NÍVEL DE GÁS NA ENTRADA A0

  if (aSensor >= 100) // CONDICIONAL PARA LIGAR E DESLIGAR A SIRENE AUTOMATICAMENTE
  {
    digitalWrite(sirene, LOW);
  }
  else
  {
    digitalWrite(sirene, HIGH);
  }
 
  if(digitalRead(botao)== LOW){  // CONDICIONAL PARA DESLIGAR A SIRENE PELO BOTÃO EM QUANTO O BOTÃO FOR PRECIONADO
  digitalWrite(sirene, HIGH);
  }

  if(aSensor <= 99)
  {
  lcd.print("Sem vazamento");
  lcd.setCursor(0, 1); // POSICIONA O CURSOR NA PRIMEIRA COLUNA DA LINHA 2
  lcd.print("detectado");
  lcd.setCursor(0, 2);
  delay(1000);
  lcd.clear();
  }

  if(aSensor >= 100)
  {
  lcd.print("Gas inflamavel");
  lcd.setCursor(0,1);
  delay(1000);
  lcd.clear();
  lcd.print("Detectado");
  lcd.setCursor(0,1);
  lcd.print(aSensor);
  lcd.setCursor(0,2);
  delay(1000);
  lcd.clear();
  }
 
}
