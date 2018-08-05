#include <Servo.h>
#include <Wire.h>
#include <JY901.h>

Servo myservo;  // create servo object to control a servo
Servo fan;
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int pos_fan = 0;
int number;

void setup() {
  Serial.begin(57600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  fan.attach(10);
  JY901.StartIIC();
}

void loop() {
    JY901.GetAngle();
    Serial.println((float)JY901.stcAngle.Angle[2]/32768*180);
    char putout;
    putout=Serial.read();
    if(putout=='Z'){
       pos=Serial.parseInt();
       myservo.write(pos);
    }
    if(putout == 'F'){
       pos_fan=Serial.parseInt();
       fan.write(pos_fan);
    }
    Serial.println("duoji pos: ");
    Serial.println(pos);
    Serial.println("fan pos: ");
    Serial.println(pos_fan);
    delay(20); 
}
