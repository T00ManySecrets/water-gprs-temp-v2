void ShowSerialData()
{
  unsigned long entry = millis();
  while ( A6board.available() != 0 && millis() - entry < SERIALTIMEOUT)
    Serial.println(A6board.readStringUntil('\n'));
}
