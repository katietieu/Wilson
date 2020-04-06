#include <CapacitiveSensor.h>

CapacitiveSensor ear = CapacitiveSensor(4,2);  // ear for music
CapacitiveSensor righthand = CapacitiveSensor(8,6);  // right hand for joke
CapacitiveSensor lefthand = CapacitiveSensor(13,11);  // left hand for yes/no answer

int sensor = 0;   // heart rate sensor on analog pin 0
int signal;   // input from heart rate sensor
int threshold = 550;
int state = 0;  // used to differentiate heartbeats
int elapsedTime;    // time between 5 heartbeats
float bpm;    // calculated heart rate
float output;   // output printed to serial port

unsigned long heartbeatsRecorded[5] = {0,0,0,0,0};    // array of the last 5 heartbeats, used to calculate bpm


void setup() {
  ear.set_CS_AutocaL_Millis(0xFFFFFFFF);
  righthand.set_CS_AutocaL_Millis(0xFFFFFFFF);
  lefthand.set_CS_AutocaL_Millis(0xFFFFFFFF);
  
  Serial.begin(9600);
}

void loop() {
  signal = analogRead(sensor);

  /* CAPACITIVE TOUCH SENSORS */
  long earSensorValue = ear.capacitiveSensor(30);
  long rhSensorValue = righthand.capacitiveSensor(30);
  long lhSensorValue = lefthand.capacitiveSensor(30);

  if (earSensorValue >= threshold) {
    output = 1000.0;
  } else if (rhSensorValue >= threshold) {
    output = 2000.0;
  } else if (lhSensorValue >= threshold) {
    output = 3000.0;
  } else {
    output = 0.0;
  }

  /* HEART RATE SENSOR */
  if (state == 0 && signal > threshold) {
    // shunt the current entries down in the array, losing the oldest
    heartbeatsRecorded[4] = heartbeatsRecorded[3];
    heartbeatsRecorded[3] = heartbeatsRecorded[2];
    heartbeatsRecorded[2] = heartbeatsRecorded[1];
    heartbeatsRecorded[1] = heartbeatsRecorded[0];
    heartbeatsRecorded[0] = millis();    // add the newest beat time at the top

    elapsedTime = heartbeatsRecorded[0] - heartbeatsRecorded[4];
    bpm = (1.0 / (elapsedTime / 5.0)) * 1000.0 * 60.0;    // calculate beats per minute
    Serial.println(output + bpm);
    
    state = 1;  // on beat

  } else if (state == 1 && signal <= threshold) {
    state = 0;  // off beat
  }
  
  delay(10);
}
