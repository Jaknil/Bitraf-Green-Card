/*
 Version 0.1 Bitraf-Green-Card

Function
To test the concept of a automatic watering system
 
Features
Pumps water for 1 second after 6 seconds if the moisture sensor is dry.
 */

int dry = 0;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
  pinMode(7, INPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
 
  dry = digitalRead(7);
   Serial.print("Dry? (dry = 1, wet = 0  :"); 
   Serial.println(dry); 
  digitalWrite(13, dry);   // turn the pump on (if it is dry)
  delay(1000);              // wait for a second
  digitalWrite(13, LOW);    // turn the pump off by making the voltage LOW
  delay(6000);              // wait for a second
}
