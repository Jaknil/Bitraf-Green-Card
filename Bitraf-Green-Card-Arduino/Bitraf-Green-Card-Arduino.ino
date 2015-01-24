/*
 
 */
//SETUP SHIELD
int PumpPin_1 = 6;
int PumpPin_2 = 7;
int SensorPin_1 = 8;
int SensorPin_2 = 9;

//SETUP TIMERS In miliseconds
int TimeBetweenPumpAction = 20000; 
int PumpTime= 5000;

//SETUP SENSORS
int SensorIsDry_1 = 0;
int SensorIsDry_2 = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pins as an outputs and inputs.
  pinMode(PumpPin_1, OUTPUT);
  pinMode(PumpPin_2, OUTPUT);
  pinMode(SensorPin_1, INPUT);
  pinMode(SensorPin_2, INPUT);
  Serial.begin(9600); //Setting the baud rate for serial communication
}

// the loop function runs over and over again forever
void loop() {
  Serial.println("Looping successfully!");  //To show that the program runs
  SensorIsDry_1 = digitalRead(SensorPin_1);
  SensorIsDry_2 = digitalRead(SensorPin_2);
  Serial.println(SensorIsDry_2);  
  Serial.println(SensorIsDry_2);  
  
  Serial.println(SensorIsDry_1);
  digitalWrite(6, HIGH);  // turn the pump on 
  delay(1000);              // wait for a second
  digitalWrite(6, LOW);    // turn the pump off by making the voltage LOW
  
    delay(2000);              // wait for # miliseconds

digitalWrite(7, HIGH);  // turn the pump on 
  delay(1000);              // wait for a second
  digitalWrite(7, LOW);    // turn the pump off by making the voltage LOW
   
    delay(2000);              // wait for # miliseconds

}
