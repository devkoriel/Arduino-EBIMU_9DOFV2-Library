#include <EBIMU.h>

EBIMU ahrs;

float angle[3];

void setup() {
  Serial.begin(57600);
  Serial.flush();

  ahrs.initialize(115200);
}

void loop() {
  while(ahrs.getEulerAngles(angle) != 1){
    /*
     * Waiting for data ready
     */
  }
  
  Serial.print("Roll : ");
  Serial.print(angle[0]);
  Serial.print("\tPitch : ");
  Serial.print(angle[1]);
  Serial.print("\tYaw : ");
  Serial.println(angle[2]);
}
