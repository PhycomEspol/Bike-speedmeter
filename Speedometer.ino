// include the library code:
#include <LiquidCrystal.h>

#define RADIO_LLANTA 0.37
#define PI           3.14

#define BUTTON       8

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

double distancia{0};

void setup() {
  lcd.begin(16, 2);
  pinMode(BUTTON, INPUT); 
}

void printVelocidad(int x, int y) {
    int segundos{millis() / 1000};
    int velocidad{distancia / (segundos < 1 ? 1 : segundos)};
  	lcd.setCursor(x, y);
  	lcd.print("Speed: ");
    lcd.print(max(velocidad, 0));
  	lcd.print("m/s");
}

void printDistancia(int x, int y) {
  	lcd.setCursor(0, 1);
  	lcd.print("Dist:  ");
  	lcd.print(distancia);
  	lcd.print("m");
}

void avanzar() {
  distancia += 2 * PI * RADIO_LLANTA; 
}

void loop() { 
  int val {digitalRead(BUTTON)};
  
  if (val == HIGH) {
	avanzar();
  }
  
  printVelocidad(0, 0);
  printDistancia(0, 1);
}
 