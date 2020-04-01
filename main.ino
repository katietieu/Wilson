int sensor = 0;
int LED = 13;

int signal;
int threshold = 550;

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  signal = analogRead(sensor);

  Serial.println(signal);

  if (signal > threshold) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }

  delay(10);
}
