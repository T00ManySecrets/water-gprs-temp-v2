bool A6begin() {
  
  A6board.println("AT+CREG?");
  byte hi = A6waitFor("1,", "5,", 1500);  // 1: registered, home network ; 5: registered, roaming
  while ( hi != OK) {
    A6board.println("AT+CREG?");
    hi = A6waitFor("1,", "5,", 1500);
    
    
  }
  
  if (A6command("AT&F0", "OK", "yy", 5000, 2) == OK) {   // Reset to factory settings
    if (A6command("ATE0", "OK", "yy", 5000, 2) == OK) {  // disable Echo
      if (A6command("AT+CMEE=2", "OK", "yy", 5000, 2) == OK) return OK;  // enable better error messages
      else return NOTOK;
      
    }
  }
}
