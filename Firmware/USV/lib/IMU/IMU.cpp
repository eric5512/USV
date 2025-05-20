#include "IMU.h"

IMU::IMU() {
    Wire.begin();
    mpu.initialize();

    if(mpu.testConnection() ==  false) { return; }

    mpu.setXAccelOffset(X_ACCEL_OFF);
    mpu.setYAccelOffset(Y_ACCEL_OFF);
    mpu.setZAccelOffset(Z_ACCEL_OFF);
    mpu.setXGyroOffset(X_GYRO_OFF);
    mpu.setYGyroOffset(Y_GYRO_OFF);
    mpu.setZGyroOffset(Z_GYRO_OFF);
}

bool IMU::read(Vector3<int16_t> &gyro, Vector3<int16_t> &accel)
{
    if (!mpu.testConnection()) return false;
    mpu.getMotion6(&accel.x, &accel.y, &accel.z, &gyro.x, &gyro.y, &gyro.z);
    return true;
}
