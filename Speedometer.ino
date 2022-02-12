// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int button = 8;
int val = 0;
int count = 0;
int vueltas;
float radioLlanta = 0.37; //Radio de la llanta en cm


void setup() {
  
  lcd.begin(16, 2);

  pinMode(button, INPUT);  
  
}


void loop() { 
  
  val = digitalRead(8);
  if (val == HIGH ) {
    vueltas = count ++;
	delay(250);
  }
  	lcd.setCursor(0, 0);
    lcd.print("Velocidad: ");
    lcd.setCursor(0, 1);
  	float distancia = (2 * 3.14 * radioLlanta);
      
    lcd.print("Recorrido:");
	lcd.print(distancia*vueltas);
  	lcd.print("m");

}
 