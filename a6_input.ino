void A6input() {
  String hh;
  char buffer[100];
  while (1 == 1) {
    if (Serial.available()) {
      hh = Serial.readStringUntil('\n');
      hh.toCharArray(buffer, hh.length() + 1);
      if (hh.indexOf("ende") == 0) {
        A6board.write(end_c);
        Serial.println("ende");
      } else {
        A6board.write(buffer);
        A6board.write('\n');
      }
    }
    if (A6board.available()) {
      Serial.write(A6board.read());
    }
  }
}
