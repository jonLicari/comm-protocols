#include <Wire.h>

#define ADDR1 6 // Define address of slave 1 to 6

void setup() {
  Wire.begin(ADDR1);
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(100); // Do nothing

}

void receiveEvent(int howMany) {
  char c; // Read data into a character
  int d;  // Read data into an integer

  while(1 < Wire.available()) { // While bytes exist to be read...
    c = Wire.read();
    Serial.print(c);
  }
  d = Wire.read();
  Serial.println(d);
}
