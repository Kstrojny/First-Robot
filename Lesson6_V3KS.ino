#include <Servo.h>          // include Servo library
Servo myServo;              // create a servo object named myServo
const int potPin = A0;      // set name of pin AO to potPin. Connected to potentiometer.
const int buttonPin = 2;    // set name of pin 7 to buttonPin. 
int potValue = 0;           // variable to read the value from potentiometer. Tracks analog value from 0 - 1023 of potentiometer
int servoAngle = 0;         // variable to set the angle for the servo. Will track the angle assigned to the servo from 0 - 179

void setup() {
  myServo.attach(3);    // attaches the servo on pin 9 to the myServo object
  Serial.begin(9600);   // open a serial connecion to the computer
}

void loop() {
  if(digitalRead(buttonPin) == HIGH) {          // if the button is pressed
    myServo.write(179);                         // move the servo to kick the ball
  }
  else {
  potValue = analogRead(potPin);                // store the potentiometer value in a variable. Analog signals have a range from 0 - 1023
  servoAngle = map(potValue, 0, 1023, 0, 179);  // scale potentiometer value to the servo
  myServo.write(servoAngle);                    // turn the servo to angle variable. Determined by above analog input, calculated by map
  }
  Serial.print("potValue: ");                   // print a label for the potValue variable
  Serial.print(potValue);                       // print the potValue variable
  Serial.print(", servoAngle: ");               // print a label for the servoAngle variable
  Serial.println(servoAngle);                   // print the servoAngle value
  delay(100);                                   // wait for the servo to get there
  
}
