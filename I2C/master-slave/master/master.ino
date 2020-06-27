#include <Wire.h>

void setup() {
  Wire.begin(); // default bc we have only one master
  
}

byte x = 0;

void loop() {
  Wire.beginTransmission(6);  // address of slave
  Wire.write("x is ");
  Wire.write(x);
  Wire.endTransmission();

  x++;

  delay(500);
}
