#include <EBIMU.h>

EBIMU ahrs;

float angle[3];
float gyro[3];

void setup() {
  Serial.begin(57600);
  Serial.flush();

  ahrs.initialize(115200);
}

void loop() {
  while(ahrs.getEulerAnglesGyro(angle, gyro) != 1){
    /*
     * Waiting for data ready
     */
  }

  Serial.print("Roll : ");
  Serial.print(angle[0]);
  Serial.print(" Pitch : ");
  Serial.print(angle[1]);
  Serial.print(" Yaw : ");
  Serial.print(angle[2]);

  Serial.print(" Roll Gyro : ");
  Serial.print(gyro[0]);
  Serial.print(" Pitch Gyro : ");
  Serial.print(gyro[1]);
  Serial.print(" Yaw Gyro : ");
  Serial.println(gyro[2]);
}
