#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);

const int tempPin = 0;
const int lightPin = 1;
const int enablePin = 11;
int roomTemp = 25;
int lightLevel, high = 0, low = 1023;

float tempVoltage, degreesF, degreesC;

void setup() {
  
  lcd.begin(16,2);
  lcd.clear();
  pinMode(enablePin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  tempVoltage = getVoltage(tempPin);
  degreesC = (tempVoltage - 0.5) * 100.0;
  degreesF = degreesC * (9.0/5.0) + 32.0;


  //Looks for photoreading
  lightLevel = analogRead(lightPin);


  
  lcd.setCursor(0,0);
  lcd.print(degreesF);
  lcd.setCursor(6,0);
  lcd.print("Deg F");
  lcd.setCursor(0,1);
  lcd.print(lightLevel);
  delay(1000);
  lcd.clear();
}

float getVoltage(int pin) {
  // Converts analog voltage reading (0-1023) to 0-5V reading
  return analogRead(pin)*0.004882814;
}

