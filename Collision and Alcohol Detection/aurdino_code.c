#define green 4
#define orange 3
#define red 2
#define Buzzer 5
#define Sensor A0
#include <LiquidCrystal.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

void setup()
{
  lcd.begin(16, 2);
  for (int i = 2; i < 6; i++)
    pinMode(i, OUTPUT);

  Serial.begin(9600);
}

void loop()
{

  for (int i = 2; i < 6; i++)
    digitalWrite(i, LOW);

  status_Indicator();
}

void status_Indicator()
{
  lcd.clear();
  int sensorg = analogRead(A0);
  int sensorp = analogRead(A1);
  Serial.println(sensorg);
  Serial.println(sensorp);
  if (sensorg >= 40)
  {
    digitalWrite(red, HIGH);
    tone(Buzzer, 250);
    lcd.setCursor(0, 0);
    lcd.print("High alcohol OR");
    lcd.setCursor(0, 1);
    lcd.print("Smoke detected");
    delay(500);
    noTone(Buzzer);
  }
  else if (sensorg >= 33)
  {
    digitalWrite(orange, HIGH);

    delay(500);
  }
  else
  {
    digitalWrite(green, HIGH);

    delay(500);
  }
  if (sensorp >= 400)
  {
    tone(Buzzer, 250);
    lcd.setCursor(0, 0);
    lcd.print("Crash");
    lcd.setCursor(0, 1);
    lcd.print("Detected");
    delay(500);
    noTone(Buzzer);
  }
  delay(10);
}