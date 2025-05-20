#include "GPS.h"

GPS::GPS() {
    SERIAL_PORT.begin(GPSBaud);
}


bool GPS::read(TinyGPSLocation **loc) {
    if (SERIAL_PORT.available() > 0 && gps.encode(SERIAL_PORT.read()) && gps.location.isValid()) {
        *loc = &gps.location;
        return true;
    }

    return false;
}