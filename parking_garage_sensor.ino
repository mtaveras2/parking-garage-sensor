#include <Servo.h>


#define trigPin 11
#define echoPin 10
#define servoPin 12

Servo parkingGate;

void setup() {
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  digitalWrite(trigPin, LOW);
  parkingGate.attach(servoPin);
  parkingGate.write(0);
}

void loop() {
  
  if (checkDistance() <= 5.00) {
    parkingGate.write(90);
    delay(5000);
  
  } else {
    parkingGate.write(0);
  
  }

  delay(100);
}

float checkDistance() {
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  float duration = pulseIn(echoPin, HIGH);
  float distance = (duration * .0343) / 2;    
  Serial.println(distance);
  return distance;  // in cm
}
