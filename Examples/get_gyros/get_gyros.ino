#include <EBIMU.h>

EBIMU ahrs;

float gyro[3];

void setup() {
  Serial.begin(57600);
  Serial.flush();

  ahrs.initialize();
}

void loop() {
  while(ahrs.getGyro(gyro) != 1){
    /*
     * Waiting for data ready
     */
  }

  Serial.print("Roll Gyro : ");
  Serial.print(gyro[0]);
  Serial.print(" Pitch Gyro : ");
  Serial.print(gyro[1]);
  Serial.print(" Yaw Gyro : ");
  Serial.println(gyro[2]);
}
