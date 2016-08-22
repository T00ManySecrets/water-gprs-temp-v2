String A6read() {
  String reply = "";
  if (A6board.available())  {
    reply = A6board.readString();
  }
  //  Serial.print("Reply: ");
  //  Serial.println(reply);
  return reply;
}
