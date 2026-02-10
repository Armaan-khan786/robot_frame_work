HardwareSerial mySerial(2);

void setup() {
  Serial.begin(115200);
  mySerial.begin(9600, SERIAL_8N1, 16, 17);

  Serial.println("RECEIVER READY");
}

void loop() {
  while (mySerial.available()) {
    String msg = mySerial.readStringUntil('\n');
    msg.trim();                 // remove \r or spaces
    if (msg.length() > 0) {
      Serial.println(msg);      // send to USB (Python reads this)
    }
  }
}
