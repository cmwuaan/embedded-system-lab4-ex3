#include <Arduino.h>

#define optRes A0
#define led 3

int brightness = 0;
int maxBrightness = 255;
int fadeAmount = 5;
int maxValue = 1024;

void setup()
{
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop()
{
  int value = analogRead(optRes);
  brightness = !value ? 0 : map(value, 0, maxBrightness, 0, maxValue) + fadeAmount;
  analogWrite(led, maxBrightness - brightness < 0 ? 0 : maxBrightness - brightness);
  delay(30);
}
