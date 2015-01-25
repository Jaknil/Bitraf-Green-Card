/*
 Timers and controls for two pumps and two moisture sensors.
 
 
 */
//SETUP SHIELD //Figure out which pins that your shield connects to.
int PumpPin_1 = 6;  
int PumpPin_2 = 7;
int SensorPin_1 = 8;
int SensorPin_2 = 9;

//SETUP PUMPING TIMERS In miliseconds
//How often should the plants be inspected and watered if needed? Allow for some time for the water to soak into the soil. 
int TimeBetweenPumpAction = 5000;  //Typically 20 000 milliseconds.
//How long should the pump run for when it pumps? 
int PumpTime= 1000; //Typically 5000 milliseconds.
//Should the pump interupt pumping when the sensor gets moist again or keep going?
int InteruptPump = 1; // 1 = interupt pump; //Not yet implemented

//SETUP SENSORS
int SensorIsDry_1 = 0;
int SensorIsDry_2 = 0;

//SETUP OTHER
int loops = 0;


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pins as an outputs and inputs.
  pinMode(PumpPin_1, OUTPUT);
  pinMode(PumpPin_2, OUTPUT);
  pinMode(SensorPin_1, INPUT);
  pinMode(SensorPin_2, INPUT);
  Serial.begin(9600); //Setting the baud rate for serial communication
for (int i=0; i <= 20; i++){Serial.println("");} //Prints 20 rows of nothing to clean the serial monitor screen. 
  
}

// the loop function runs over and over again forever
void loop() {
  
 //To show the PC what the arduino is reading
   Serial.println("Dry = 1, Wet = 0");
  SensorIsDry_1 = digitalRead(SensorPin_1);
  SensorIsDry_2 = digitalRead(SensorPin_2);
  Serial.print("Sensor 1: ");  
  Serial.println(SensorIsDry_1);  
  Serial.print("Sensor 2: "); 
  Serial.println(SensorIsDry_2);  
  Serial.print("This was loop nr: "); 
  Serial.println(loops);
  Serial.println("");  
  loops++;
  
  //Run the pumps
  digitalWrite(PumpPin_1, SensorIsDry_1);  // turn the pump on IF the Sensor is dry 
  digitalWrite(PumpPin_2, SensorIsDry_2);  // turn the pump on IF the Sensor is dry
  delay(PumpTime);              // wait while pumping
  digitalWrite(PumpPin_1, LOW);    // turn the pump off by making the voltage LOW
  digitalWrite(PumpPin_2, LOW);    // turn the pump off by making the voltage LOW
    delay(TimeBetweenPumpAction);              // wait for # miliseconds

 
   

}
