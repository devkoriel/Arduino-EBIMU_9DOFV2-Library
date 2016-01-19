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

float dataLast[3] = { 0, };
float samplingTime, samplingTimeLast;

unsigned long t = 0;
unsigned long tLast = 0;

void seperator(char *SBuf, float *data, int size)
{
	seg = strtok(SBuf, ",");

	for (int i = 0; i < size; i++){
		data[i] = atof(seg);
		seg = strtok(NULL, ",");
	}
}

void gyroCalc(float *data, float *data2)
{
	t = millis();
	samplingTimeLast = samplingTime;
	samplingTime = (float)t - (float)tLast;
	tLast = t;

	if (samplingTime < 0) samplingTime = samplingTimeLast;

	for (int n = 0; n < SIZE_OF_GYRO; n++){
		data2[n] = (data[n] - dataLast[n]) / (samplingTime / 1000);
	}

	dataLast[0] = data[0];
	dataLast[1] = data[1];
	dataLast[2] = data[2];
}

EBIMU::EBIMU()
{
}

void EBIMU::initialize(int baudrate)
{
#if EBIMU_SERIAL_PIN == 1
	Serial1.begin(baudrate);

#elif EBIMU_SERIAL_PIN == 2
	Serial2.begin(baudrate);

#elif EBIMU_SERIAL_PIN == 3
	Serial3.begin(baudrate);
#endif
}

uint8_t EBIMU::getEulerAngles(float *data)
{
#if EBIMU_SERIAL_PIN == 1
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

#elif EBIMU_SERIAL_PIN == 2
	if (Serial2.available()){
		buf[i] = Serial2.read();
		i++;

		if (buf[i - 1] == EOL_LF) buf[i - 1] = ',';

		if (buf[i - 1] == SOL){
			seperator(buf, data, SIZE_OF_EULER_ANGLES);
			i = 0;
			return 1;
		}
	}
	return -1;

#elif EBIMU_SERIAL_PIN == 3
	if (Serial3.available()){
		buf[i] = Serial3.read();
		i++;

		if (buf[i - 1] == EOL_LF) buf[i - 1] = ',';

		if (buf[i - 1] == SOL){
			seperator(buf, data, SIZE_OF_EULER_ANGLES);
			i = 0;
			return 1;
		}
	}
	return -1;
#endif
}

uint8_t EBIMU::getQuaternion(float *data)
{
#if EBIMU_SERIAL_PIN == 1
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

#elif EBIMU_SERIAL_PIN == 2
	if (Serial2.available()){
		buf[i] = Serial2.read();
		i++;

		if (buf[i - 1] == EOL_LF) buf[i - 1] = ',';

		if (buf[i - 1] == SOL){
			seperator(buf, data, SIZE_OF_QUATERNION);
			i = 0;
			return 1;
		}
	}
	return -1;

#elif EBIMU_SERIAL_PIN == 3
	if (Serial3.available()){
		buf[i] = Serial3.read();
		i++;

		if (buf[i - 1] == EOL_LF) buf[i - 1] = ',';

		if (buf[i - 1] == SOL){
			seperator(buf, data, SIZE_OF_QUATERNION);
			i = 0;
			return 1;
		}
	}
	return -1;
#endif
}

uint8_t EBIMU::getGyro(float *data)
{
#if EBIMU_SERIAL_PIN == 1
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

#elif EBIMU_SERIAL_PIN == 2
	if (Serial2.available()){
		buf[i] = Serial2.read();
		i++;

		if (buf[i - 1] == EOL_LF) buf[i - 1] = ',';

		if (buf[i - 1] == SOL){
			seperator(buf, data, SIZE_OF_GYRO);
			i = 0;
			return 1;
		}
	}
	return -1;

#elif EBIMU_SERIAL_PIN == 3
	if (Serial3.available()){
		buf[i] = Serial3.read();
		i++;

		if (buf[i - 1] == EOL_LF) buf[i - 1] = ',';

		if (buf[i - 1] == SOL){
			seperator(buf, data, SIZE_OF_GYRO);
			i = 0;
			return 1;
		}
	}
	return -1;
#endif
}

uint8_t EBIMU::getEulerAnglesGyro(float *data, float *data2)
{
	if (Serial1.available()){
		buf[i] = Serial1.read();
		i++;

		if (buf[i - 1] == EOL_LF) buf[i - 1] = ',';

		if (buf[i - 1] == SOL){
			seperator(buf, data, SIZE_OF_EULER_ANGLES);
			i = 0;

			gyroCalc(data, data2);
			return 1;
		}
	}
	return -1;
}