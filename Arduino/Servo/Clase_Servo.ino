#include <Servo.h>

Servo servo_9;
int servoPosition = 0;

void setup() {
  servo_9.attach(9);
  servo_9.write(servoPosition);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();
    if (command == '1') {
      servo_9.write(180);
      servoPosition = 180;
    } else if (command == '0') {
      servo_9.write(0);
      servoPosition = 0;
    }
  }
}
