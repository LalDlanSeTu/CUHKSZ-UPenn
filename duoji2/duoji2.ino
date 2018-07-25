#include <Servo.h>
#include <Wire.h>
#include <JY901.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
    Serial.begin(57600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  JY901.StartIIC();
}


void loop() {
      JY901.GetAngle();
    pos=(float)JY901.stcAngle.Angle[2]/32768*180;
    if(pos < 0){
      pos=-pos;
    }
    myservo.write(pos);
    Serial.println(pos);
    delay(15); 

}
