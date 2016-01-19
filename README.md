# ProjectD
Autonomous Drone Project
* DronixCopter(RC)
* DronixCopter(AltHold)
* DronixCopter(Pos)

# DronixCopter(RC)
## Note
An arduino sketch for controlling a quadcopter. Uses RC and the MPU-6050 chip.

This is a simple arduino sketch that allows you to take over control over a quadcopter with the arduino board. Because I've made this sketch primarily for private use, the sketch relies on certain hardware, but should also be usable with different hardware with a bit of customization work.

This sketch was only tested on the Arduino Uno rev 3 board, so it might not work on other arduino-like boards without making changes.

The arducopter sketch needs three things to work at the moment:
* A RC receiver with a minimum of 4 channels
* The MPU-6050 gyro/accelerometer chip
* Four ESCs with a known minimum and maximum value

At the moment, the sketch doesn't implement all features as I can only update it as fast as I can run new tests with my quadcopter. Complete features are:

* Arming of ESCs with given min/max values
* Control over pitch, roll and yaw through double PID loop
* Control over pitch, roll and yaw through RC
* Controll over vertical speed through RC
* Calculation of current angle and gyro via complementary filter
* Manual calibration of pitch & roll

Planned features are:
* Altitude hold using MS5611 barometer sensor
* Position hold using GPS & Compass sensor
* Adaptive PID control

## How to modify
> **Note:**
> If you have questions about the code or the compatability of the code and certain hardware, you've spotted a bug or need help with your project, please open a new github issue rather than sending me an e-mail. That way, I don't have to answer questions twice and you'll get quicker answers. Thank you.

1. You should modify ESC, RC to fit your hardware configuration.
2. You should set ROLL_OFFSET, PITCH_OFFSET after checking angle drift via serial monitor.
3. You should tune PID gains properly.

### Balancing test video(DronixCopter(RC))
[![IMAGE ALT TEXT](http://img.youtube.com/vi/OuCgH725ByI/0.jpg)](http://www.youtube.com/watch?v=OuCgH725ByI "DronixCopter(RC) balancing test")


# Warnings
You may get **seriously injured** if you start the quadcopter before PID gains tuned properly.


# License
This project is licensed under the MIT license (see the included license file for more information).

Note: The libraries used in this project might not be licensed under the MIT license. I've made sure that the usage of all libraries as a part of this project, my modifications and the redistribution of the modified and unmodified libraries are permitted by the respective licenses, but the permissions of the MIT license might not apply, especially in regard to relicensing.
