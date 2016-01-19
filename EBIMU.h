#include "Arduino.h"

#define EBIMU_DEFAULT_SERIAL_PIN	1
#define EBIMU_DEFAULT_BAUDRATE		115200

class EBIMU{
public:
	EBIMU();

	void initialize();
	
	uint8_t getEulerAngles(float *data); //default setting
	uint8_t getQuaternion(float *data);
	uint8_t getGyro(float *data);

private:
	int _pin;
	int _baudrate;
};