/*
 * L3GD20H_typedef.h
 *
 *  Created on: 28 sie 2017
 *      Author: Chupacabra
 */

#ifndef L3GD20H_TYPEDEF_H_
#define L3GD20H_TYPEDEF_H_

typedef enum L3GD20H_regAddr
{
	L3GD20H_WHO_AM_I       = 0x0F,

	L3GD20H_CTRL1          = 0x20,
	L3GD20H_CTRL2          = 0x21,
	L3GD20H_CTRL3          = 0x22,
	L3GD20H_CTRL4          = 0x23,
	L3GD20H_CTRL5          = 0x24,
	L3GD20H_REFERENCE      = 0x25,
	L3GD20H_OUT_TEMP       = 0x26,
	L3GD20H_STATUS         = 0x27,

	L3GD20H_OUT_X_L        = 0x28,
	L3GD20H_OUT_X_H        = 0x29,
	L3GD20H_OUT_Y_L        = 0x2A,
	L3GD20H_OUT_Y_H        = 0x2B,
	L3GD20H_OUT_Z_L        = 0x2C,
	L3GD20H_OUT_Z_H        = 0x2D,

	L3GD20H_FIFO_CTRL      = 0x2E,
	L3GD20H_FIFO_SRC       = 0x2F,

	L3GD20H_IG_CFG         = 0x30,
	L3GD20H_IG_SRC         = 0x31,
	L3GD20H_IG_THS_XH      = 0x32,
	L3GD20H_IG_THS_XL      = 0x33,
	L3GD20H_IG_THS_YH      = 0x34,
	L3GD20H_IG_THS_YL      = 0x35,
	L3GD20H_IG_THS_ZH      = 0x36,
	L3GD20H_IG_THS_ZL      = 0x37,
	L3GD20H_IG_DURATION    = 0x38,

	L3GD20H_LOW_ODR        = 0x39
}L3GD20H_regAddr;


#endif /* L3GD20H_TYPEDEF_H_ */
