/*
  RTS as PTT.

  This example code is in the public domain.

*/

#define PIN_11 11

extern __xdata uint8_t controlLineState;

void setup() {
  Serial0_begin(9600);
  pinMode(PIN_11, OUTPUT);
  digitalWrite(PIN_11, LOW);
  // delay(6000);
}

void loop() {
  // https://github.com/DeqingSun/ch55xduino/blob/ch55xduino/ch55xduino/ch55x/cores/ch55xduino/USBCDC.c#L22
  // USBSerial_print((currentLineState & 0x02));

  if ((controlLineState & 0x02) == 2) { // is rts active?
    digitalWrite(PIN_11, HIGH);
  } else {
    digitalWrite(PIN_11, LOW);
  }
  delay(1);
}
