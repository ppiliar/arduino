/*
  DigitalReadSerial

  Reads a digital input on pin 2, prints the
  result to the serial monitor

  This example code is in the public domain.
*/
#include <Servo.h>

Servo servo_12;

int buttonState = 0;
bool open = false;
void setup()
{
  pinMode(13, OUTPUT);
  pinMode(2, INPUT);
  servo_12.attach(12);
  Serial.begin(9600);
  
  servo_12.write(0);
}

void loop()
{
  delay(1000); // Wait for 1000 millisecond(s)
  // read the input pin
  buttonState = digitalRead(2);
  // print out the state of the button
  if(buttonState && !open){
    open = true;
    rampOpen();
  }
  Serial.println(buttonState);
  delay(10); // Delay a little bit to improve simulation performance
}

void rampOpen(){
  Serial.println("openRamp");
  servo_12.write(90);
  rampUp();
}

void rampUp(){
  Serial.println("ramp up");
  delay(10000);
  rampDown();
}

void rampDown(){
  Serial.println("downRamp");
  servo_12.write(0); 
  open = false;
}
