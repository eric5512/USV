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

//CODE TEST Motor
// #include<Servo.h>
// #include<Arduino.h>

// Servo m1; //motor #1
// void setup()
// {
//   m1.attach(6); //connect the signal pin of esc to any pwm enabled pin on the arduino. In this case its pin 6
//   delay(1); // no use of this line -_-
//   m1.write(40);// this arms the HW esc
//   delay(3000);// this delay is a must.
// }
// void loop()
// {
//   m1.write(50);
// }

#include <Arduino.h>
#include <Servo.h>
#include <IRremote.hpp>

#define IR_RECEIVE_PIN 21

#define SERVO_ZERO     90
#define SERVO_RIGHT    135
#define SERVO_LEFT     45

#define BLDC_ON        70
#define BLDC_OFF       40

Servo servo;
Servo bldc;

void reset_state();

void setup() {
  Serial.begin(115200);
  servo.attach(7);
  bldc.attach(6);
  reset_state();
  delay(3000);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);  
}

void loop() {
  if (IrReceiver.decode()) {
    switch (IrReceiver.decodedIRData.command) {
      case 128: // Reset
      reset_state();
      Serial.println("Reset");
      break;
      case 101: // Start BLDC
      bldc.write(BLDC_ON);
      Serial.println("Start BLDC");
      break;
      case 102: // Servo right 
      servo.write(SERVO_RIGHT);
      Serial.println("Servo right");
      break;
      case 100: // Servo left 
      servo.write(SERVO_LEFT);
      Serial.println("Servo left");
      break;
    }
    delay(200);
    IrReceiver.resume();
  }
}

void reset_state() {
  servo.write(SERVO_ZERO);
  bldc.write(BLDC_OFF);
}