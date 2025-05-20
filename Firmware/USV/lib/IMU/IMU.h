#pragma once

#include <MPU6050.h>
#include "Vector3.h"

#define X_ACCEL_OFF 0
#define Y_ACCEL_OFF 0
#define Z_ACCEL_OFF 0
#define X_GYRO_OFF 0
#define Y_GYRO_OFF 0
#define Z_GYRO_OFF 0

class IMU {
private:
    MPU6050 mpu;

public:
    IMU();
    bool read(Vector3<int16_t> &gyro, Vector3<int16_t> &accel);
};
