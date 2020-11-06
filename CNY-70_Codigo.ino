#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);

void setup() {
  pinMode(A0, INPUT);
  Serial.begin(9600); lcd.begin(16,2);
}

  double vin = 0;
  double vout = 0;
  double x1 = 0;
  double x2 = 0;
  double a = 0.0146;
  double b = -0.5332;

void loop() {

  double c = 3.8929;
  
   lcd.clear();
   lcd.print("Sensor CNY-70");
  
  vin = analogRead(A0);

  vout = (vin*5)/1023;
  
  c=c-vout;

  //x1=(-b+sqrt(pow(b,2)-4*a*c))/(2*a);
  
  x2=(-b-sqrt(pow(b,2)-4*a*c))/(2*a);

  lcd.setCursor(0,1);
  lcd.print("Distance:");
  lcd.print(x2);
  lcd.print("mm");
  //Serial.print("x1: ");
  //Serial.println(x1);

  delay(1000);

}
