#include <SPI.h>

int buttonValue = 0;
int button = 2;
int led = 3;
int m;
int masterRec = 0;
int masterSend = 0;
  
void setup() {  

  pinMode(button, INPUT);
  pinMode(led, OUTPUT);

  Serial.begin(115200);
  SPI.begin();  // Sets SCK, MOSI, SS to OUTPUT & pulls SCK, MOSI LOW & SS HIGH
  SPI.setClockDivider(SPI_CLOCK_DIV8);
  digitalWrite(SS, HIGH); // 
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonValue = digitalRead(button);

  if (buttonValue == HIGH) {
    m = 1;
  }
  else {
    m = 0;
  }

  digitalWrite(SS, LOW);    // Master will be sending data
  masterSend = m;           // Send push button value

  masterRec = SPI.transfer(masterSend); // Send data across the bus

  if (masterRec == 1) {
    digitalWrite(led, HIGH);
    Serial.println("Master LED is ON");  
  }
  else {
    digitalWrite(led, LOW);
    Serial.println("Master LED is OFF");  
  }
}
