#include "Arduino.h"
#include "EBIMU.h"

#define SOL						0x2A
#define EOL_CR					0x0D
#define EOL_LF					0x0A

#define RBUF_SIZE				64
#define SIZE_OF_EULER_ANGLES	3
#define SIZE_OF_QUATERNION		4
#define SIZE_OF_GYRO			3

/*
ASCII OUTPUT DATA FORMAT
| SOL | 	DATA 1	  | sp |	DATA 2	  | sp | ... | sp |		DATA n	 |  EOL  |
|  *  |  ascii data1  | ,  | ascii data 2 | ,  | ... | ,  | ascii data n | CR LF |

Parameter				|	 Value	  | Unit
________________________|_____________|______
			|	roll	| -180 ~ +180 |
Output Range|	pitch	| -90 ~ +90	  |  deg
			|	yaw		| -180 ~ +180 |
*/

int i = 0;
char buf[RBUF_SIZE] = { 0, };
char *seg;

void seperator(char *SBuf, float *data, int size)
{
	seg = strtok(SBuf, ",");

	for (int i = 0; i < size; i++){
		data[i] = atof(seg);
		seg = strtok(NULL, ",");
	}
}

EBIMU::EBIMU()
{
	_pin = EBIMU_DEFAULT_SERIAL_PIN;
	_baudrate = EBIMU_DEFAULT_BAUDRATE;
}

void EBIMU::initialize()
{
	switch (_pin)
	{
	case 1:
		Serial1.begin(_baudrate);
		break;

	case 2:
		Serial2.begin(_baudrate);
		break;

	case 3:
		Serial3.begin(_baudrate);
		break;
	}
}

uint8_t EBIMU::getEulerAngles(float *data)
{
	if (Serial1.available()){
		buf[i] = Serial1.read();
		i++;

		if (buf[i - 1] == EOL_LF) buf[i - 1] = ',';

		if (buf[i - 1] == SOL){
			seperator(buf, data, SIZE_OF_EULER_ANGLES);
			i = 0;
			return 1;
		}
	}
	return -1;
}

uint8_t EBIMU::getQuaternion(float *data)
{
	if (Serial1.available()){
		buf[i] = Serial1.read();
		i++;

		if (buf[i - 1] == EOL_LF) buf[i - 1] = ',';

		if (buf[i - 1] == SOL){
			seperator(buf, data, SIZE_OF_QUATERNION);
			i = 0;
			return 1;
		}
	}
	return -1;
}

uint8_t EBIMU::getGyro(float *data)
{
	if (Serial1.available()){
		buf[i] = Serial1.read();
		i++;

		if (buf[i - 1] == EOL_LF) buf[i - 1] = ',';

		if (buf[i - 1] == SOL){
			seperator(buf, data, SIZE_OF_GYRO);
			i = 0;
			return 1;
		}
	}
	return -1;
}