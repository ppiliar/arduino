#include <Servo.h>

int true2 = 0;

Servo servo_12;

void setup()
{
  pinMode(13, OUTPUT);
  servo_12.attach(12);

}

void loop()
{
  digitalWrite(13, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(13, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
  while (1 == 1) {
    servo_12.write(45);
  }
}
