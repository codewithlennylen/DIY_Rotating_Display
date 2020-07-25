//Includes the Arduino Stepper Library
#include <Stepper.h>

// Defines the number of steps per rotation for the stepper
const int stepsPerRevolution = 2038;
#define STEPS 32

int motorSpeed = 200;
const byte interruptPin = 2;
int steps = 0;

// Creates an instance of stepper class
// Pins entered in sequence IN1-IN3-IN2-IN4 for proper step sequence
Stepper myStepper = Stepper(STEPS, 8, 10, 9, 11);

void setup()
{
    // Nothing to do (Stepper Library sets pins as outputs)
    Serial.begin(9600);
    // attachInterrupt(digitalPinToInterrupt(interruptPin), speedChange, CHANGE);
    int potValue = analogRead(A0);
    motorSpeed = map(analogRead(A0), 0, 712, 200, 1000);
}

void loop()
{
    int potValue = analogRead(A0);
    motorSpeed = map(analogRead(A0), 0, 712, 200, 1000);
    Serial.print("PotValue: ");
    Serial.print(potValue);
    Serial.print(" :motorSpeed: ");
    Serial.println(motorSpeed);

    // Rotate CW slowly
    myStepper.setSpeed(motorSpeed);
    myStepper.step(steps);
    steps = steps + 1;
    // delay(100);

    // // Rotate CCW quickly
    // myStepper.setSpeed(motorSpeed);
    // myStepper.step(-stepsPerRevolution);
    // delay(100);
}

// void speedChange()
// {
//     motorSpeed = map(analogRead(A0), 0, 712, 200, 1000);
// }