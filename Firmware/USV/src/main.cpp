// #include <Arduino.h>
// #include <Servo.h>

// #include "IMU.h"
// #include "Vector3.h"
// #include "GPS.h"

// #define SERVO_PIN 11
// #define MOTOR_PIN 12

// #define DEBUG_ENABLE

// IMU imu;
// GPS gps;
// Servo servo;
// Servo motor;

// Vector3<int16_t> accel, gyro;
// TinyGPSLocation *loc;

// void setup() {
//   #ifdef DEBUG_ENABLE
//   Serial.begin(115200);
//   #endif

//   servo.attach(SERVO_PIN);
//   motor.attach(MOTOR_PIN);
// }

// void loop() {
//   // Get info from sensor
//   bool gps_valid = gps.read(&loc);
//   bool imu_valid = imu.read(gyro, accel);

//   // Estimate the correct values for output actuators


//   // Set actuators
  

//   // From time to time report through LoRa

// }

#include <Servo.h>
#include <Arduino.h>

Servo myservo;  // create Servo object to control a servo
// twelve Servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(7);  // attaches the servo on pin 9 to the Servo object
}

void loop() {
  myservo.write(95);
}