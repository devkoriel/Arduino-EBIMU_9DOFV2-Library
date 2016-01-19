#include "Arduino.h"

#define EBIMU_SERIAL_PIN	1

class EBIMU{
public:
	EBIMU();

	void initialize(int baudrate);
	
	uint8_t getEulerAngles(float *data); //default setting
	uint8_t getQuaternion(float *data);
	uint8_t getGyro(float *data);
	uint8_t getEulerAnglesGyro(float *data, float *data2);

private:
};