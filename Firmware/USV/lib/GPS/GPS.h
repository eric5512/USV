#pragma once

#include <TinyGPS++.h>

#define SERIAL_PORT Serial2
static const uint32_t GPSBaud = 9600;

class GPS
{
private:
    TinyGPSPlus gps;
public:
    GPS();
    bool read(TinyGPSLocation **);
};