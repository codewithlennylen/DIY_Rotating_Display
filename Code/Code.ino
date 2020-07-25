//Includes the Arduino Stepper Library
#include <Stepper.h>

// Defines the number of steps per rotation
const int stepsPerRevolution = 2038;
#define STEPS 32

// Creates an instance of stepper class
// Pins entered in sequence IN1-IN3-IN2-IN4 for proper step sequence
Stepper myStepper = Stepper(STEPS, 8, 10, 9, 11);

void setup()
{
    // Nothing to do (Stepper Library sets pins as outputs)
}

void loop()
{
    // Rotate CW slowly
    myStepper.setSpeed(350);
    myStepper.step(stepsPerRevolution);
    delay(1000);

    // Rotate CCW quickly
    myStepper.setSpeed(1000);
    myStepper.step(-stepsPerRevolution);
    delay(1000);
}