#ifndef _PWM_EXP_H_
#define _PWM_EXP_H_

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include <onion-i2c.h>




#define I2C_DEVICE_NUM			0
#define I2C_DEVICE_ADDR			0x00

#define REG_OFFSET_BYTE0		0x0
#define REG_OFFSET_BYTE1		0x1

#define REG_OFFSET_ON_BYTES		0x0
#define REG_OFFSET_OFF_BYTES	0x2

#define	PULSE_TOTAL_COUNT		4096



// type definitions
typedef enum e_PwmDriverAddr {
	PWM_EXP_DRIVER0 	= 0x06,
	PWM_EXP_DRIVER1 	= 0x0a,
	PWM_EXP_DRIVER2 	= 0x0e,
	PWM_EXP_DRIVER3 	= 0x12,
	PWM_EXP_DRIVER4 	= 0x16,
	PWM_EXP_DRIVER5 	= 0x1a,
	PWM_EXP_DRIVER6 	= 0x1e,
	PWM_EXP_DRIVER7 	= 0x22,
	PWM_EXP_DRIVER8 	= 0x26,
	PWM_EXP_DRIVER9 	= 0x2a,
	PWM_EXP_DRIVER10 	= 0x2e,
	PWM_EXP_DRIVER11 	= 0x32,
	PWM_EXP_DRIVER12 	= 0x36,
	PWM_EXP_DRIVER13 	= 0x3a,
	PWM_EXP_DRIVER14 	= 0x3e,
	PWM_EXP_DRIVER15 	= 0x42,
	PWM_EXP_DRIVER_ALL	= 0xfa
} ePwmDriverAddr;

struct pwmSetup {
	int 	driverNum;
	int 	regOffset;
	
	int 	timeStart;
	int 	timeEnd;
};


// helper functions
void 	_initPwmSetup		(pwmSetup *obj);
int 	_dutyToCount 		(int duty);

int 	_getDriverRegisterOffset (int driverNum, int &addr);
int 	_writeValue			(int addr, int value);
int 	_pwmSetTime			(pwmSetup *setup);

void 	_pwmCalculate		(int duty, int delay, pwmSetup *setup);

int 	pwmSetupDriver		(int driverNum, int duty, int delay);


#endif // _PWM_EXP_H_