# Arduino-EBIMU_9DOFV2-Library
Arduino Library for E2BOX EBIMU-9DOFV2 AHRS Module(http://www.e2box.co.kr/124)

	Mode	|	Features	|	Description
------------ | ------------ | -------------
ASCII| getEulerAngles()		|	Get Roll, Pitch, Yaw
ASCII| getQuaternion()		|	Get Quaternion
ASCII| getGyro()		|	Get Roll, Pitch, Yaw Gyros
ASCII| getEulerAnglesGyro()	|	Get Euler Angles and Gyros simultaneously 

# How to Use
You shoud change serial pin configuration, which is at the top of *EBIMU.h* header, to fit to your serial configuration.
``` c++
#include "Arduino.h"

#define EBIMU_SERIAL_PIN	1 //here!

class EBIMU{
public:
	EBIMU();

	void initialize(int baudrate);
	
	uint8_t getEulerAngles(float *data);
	uint8_t getQuaternion(float *data);
	uint8_t getGyro(float *data);
	uint8_t getEulerAnglesGyro(float *data, float *data2);

private:
};
```

# License
This library is licensed under the MIT license (see the included license file for more information).

Note: The libraries used in this project might not be licensed under the MIT license. I've made sure that the usage of all libraries as a part of this project, my modifications and the redistribution of the modified and unmodified libraries are permitted by the respective licenses, but the permissions of the MIT license might not apply, especially in regard to relicensing.
