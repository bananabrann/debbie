void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  pinMode(7, OUTPUT);
  bool setupInProgress = true;
  while
}

void loop() {
//  for (int i = 0; i < 5; i += 1) {
//    digitalWrite(LED_BUILTIN, HIGH);
//    delay(500);
//    digitalWrite(LED_BUILTIN, LOW);
//    delay(500);
//    printf("For loop");
//  }
  digitalWrite(7, HIGH);
  delay(750);
  digitalWrite(7, LOW);
  delay(750);
}