const int MOTOR = 5;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(MOTOR, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  
  digitalWrite(MOTOR, LOW);// turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  
  digitalWrite(MOTOR, HIGH);// turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}
