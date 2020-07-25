//Includes the Arduino Stepper Library
#include <Stepper.h>

// Defines the number of steps per rotation for the stepper
const int stepsPerRevolution = 2038;
#define STEPS 32

const byte interruptPin = 2;
int motorSpeed = 200;
int steps = 0;
byte buttonState = 0;
int potValue;
byte btnPressed;

// Creates an instance of stepper class
// Pins entered in sequence IN1-IN3-IN2-IN4 for proper step sequence
Stepper myStepper = Stepper(STEPS, 8, 10, 9, 11);

void setup()
{
    // Nothing to do for stepper pins(Stepper Library sets pins as outputs)
    pinMode(interruptPin, INPUT);
    Serial.begin(9600);
}

void loop()
{
    // Read the inputs
    potValue = analogRead(A0);
    motorSpeed = map(potValue, 0, 712, 200, 1000);
    btnPressed = digitalRead(interruptPin);
    if (btnPressed == 1)
    {
        directionChange();
        delay(500);
    }

    Serial.print("ButtonState: ");
    Serial.print(buttonState);
    Serial.print(" :PotValue: ");
    Serial.print(potValue);
    Serial.print(" :motorSpeed: ");
    Serial.println(motorSpeed);

    myStepper.setSpeed(motorSpeed);
    if (buttonState == HIGH)
    {
        myStepper.step(-steps);
        // steps = steps + 1;
    }
    else
    {
        myStepper.step(steps);
        // steps = steps + 1;
    }

    steps = steps + 1;
}

void directionChange()
{
    if (buttonState == 1)
    {
        buttonState = 0;
    }
    else if (buttonState == 0)
    {
        buttonState = 1;
    }
}