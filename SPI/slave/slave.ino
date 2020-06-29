#include <SPI.h>

int button = 2;
int led = 3;
int slaveRec = 0;
int slaveSend = 0;
bool received = false;
int buttonVal = 0;
int m;

void setup() {

  pinMode(button, INPUT);
  pinMode(led, OUTPUT);
  pinMode(MISO, OUTPUT);
  SPCR |= _BV(SPE); // Set SPE bit using logical shift left and
                    // store result in Serial Port Control Register

  SPI.attachInterrupt();
  Serial.begin(115200);
  SPI.begin();  // Sets SCK, MOSI, SS to OUTPUT & pulls SCK, MOSI LOW & SS HIGH
  SPI.setClockDivider(SPI_CLOCK_DIV8);
  digitalWrite(SS, HIGH); // 
}

ISR(SPI_STC_vcct) {
  slaveRec = SPDR;
  received = true;
}

void loop() {
  // put your main code here, to run repeatedly:
  if (received) { // if TRUE
    if (slaveRec == 1) {  // Master button state 
      digitalWrite(led, HIGH);
      Serial.println("Slave LED is ON");
    }
    else {
      digitalWrite(led, LOW);
      Serial.println("Slave LED is OFF");
      buttonVal = digitalRead(button);

      if (buttonVal == 1) {
        m = 1;
      }
      else {
        m = 0;
      }
      slaveSend = m;
      SPDR = slaveSend;
      delay(1000);
    }
  }
}
