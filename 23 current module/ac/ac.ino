#include "ACS712.h"

/*
  This example shows how to measure DC current
*/

// We have 30 amps version sensor connected to A4 pin of esp
// Replace with your version if necessary
ACS712 sensor(ACS712_20A, A4);

void setup() {
  Serial.begin(115200);


  // calibrate() method calibrates zero point of sensor,
  // It is not necessary, but may positively affect the accuracy
  // Ensure that no current flows through the sensor at this moment
  // If you are not sure that the current through the sensor will not leak during calibration - comment out this method
  Serial.println("Calibrating... Ensure that no current flows through the sensor at this moment");
  int zero = sensor.calibrate();
  Serial.println("Done!");
  Serial.println("Zero point for this sensor = " + zero);
}

void loop() {
  // Read current from sensor
  float I = sensor.getCurrentDC();
  
  // Send it to serial
  Serial.println(String("I = ") + I + " mA");
  
  // Wait a second before the new measurement
  delay(1000);
}
