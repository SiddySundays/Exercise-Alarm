const int led = 13;                // the pin that the LED is attached to
const int sensor = 2;              // the pin that the sensor is attached to
const int buzzer = 9;              // the pin that the buzzer is attached to
int state = LOW;             // by default, no motion detected
int val = 0;                 // variable to store the sensor status (value)
int counter = 0;
int counterOfCounter = 0;

void setup() {
  pinMode(led, OUTPUT);      // initalize LED as an output
  pinMode(sensor, INPUT);    // initialize sensor as an input
  pinMode(buzzer, OUTPUT);   // initialize buzzer as an output
  Serial.begin(9600);        // initialize serial
  digitalWrite(led, LOW);    // led default off
  delay(14000);
  digitalWrite(led, HIGH);
  tone(buzzer, 1000); // Send 1KHz sound signal...
  delay(1000);
  digitalWrite(led, LOW);
  Serial.println("Ready");
}
void loop() {
  while (counter < 3) {
    val = digitalRead(sensor);   // read sensor value
    if (val == HIGH) {
      counter++; // short cut for i= i+1
      Serial.println("counter: " + counter);
      delay(1000);
    } else {
      counter=0;
    }
  }
  if (counter == 3) {
    counterOfCounter++;
    counter=0;
    Serial.println("counterOfCounter: " + counterOfCounter);
    Serial.println("counter reset");
  }
  if (counterOfCounter == 10) {    
    digitalWrite(led, HIGH);
    noTone(buzzer);     // Stop sound...
  }
}
