/*
 * LSM303_typedef.h
 *
 *  Created on: 26 sie 2017
 *      Author: Chupacabra
 */

#ifndef LSM303_TYPEDEF_H_
#define LSM303_TYPEDEF_H_

typedef enum LSM303_axes{
	axisX		= 0,
	axisY		= 1,
	axisZ		= 2,
}LSM303_axes;

typedef enum LSM303_rate{
	rate_0Hz		= 0,
	rate_3Hz125		= 1,
	rate_6Hz25		= 2,
	rate_12Hz5		= 3,
	rate_25Hz		= 4,
	rate_50Hz		= 5,
	rate_100Hz		= 6,
	rate_200Hz		= 7,
	rate_400Hz		= 8,
	rate_800Hz		= 9,
	rate_1600Hz		= 10,
}LSM303_rate;

typedef enum LSM303_magneticRate{
	mate_3Hz125		= 0,
	mrate_6Hz25		= 1,
	mrate_12Hz5		= 2,
	mrate_25Hz		= 3,
	mrate_50Hz		= 4,
	mrate_100Hz		= 5,
}LSM303_magneticRate;

typedef enum LSM303_accelerationFullScale{
	scale_2g	= 0,
	scale_4g	= 1,
	scale_6g	= 2,
	scale_8g	= 3,
	scale_16g	= 4,

}LSM303_accelerationFullScale;

typedef enum LSM303_magnetometerFullScale{
	scale_2gauss 	= 0,
	scale_4gauss 	= 1,
	scale_8gauss 	= 2,
	scale_12gauss 	= 3,
}LSM303_magnetometerFullScale;

typedef enum LSM303_regAddr
{
  TEMP_OUT_L        = 0x05,
  TEMP_OUT_H        = 0x06,

  STATUS_M          = 0x07,

  OUT_X_L_M         = 0x08,
  OUT_X_H_M         = 0x09,
  OUT_Y_L_M         = 0x0A,
  OUT_Y_H_M         = 0x0B,
  OUT_Z_L_M         = 0x0C,
  OUT_Z_H_M         = 0x0D,

  WHO_AM_I			= 0x0F,

  INT_CTRL_M        = 0x12,
  INT_SRC_M         = 0x13,
  INT_THS_L_M       = 0x14,
  INT_THS_H_M       = 0x15,

  OFFSET_X_L_M      = 0x16,
  OFFSET_X_H_M      = 0x17,
  OFFSET_Y_L_M      = 0x18,
  OFFSET_Y_H_M      = 0x19,
  OFFSET_Z_L_M      = 0x1A,
  OFFSET_Z_H_M      = 0x1B,
  REFERENCE_X       = 0x1C,
  REFERENCE_Y       = 0x1D,
  REFERENCE_Z       = 0x1E,

  CTRL0             = 0x1F,
  CTRL1             = 0x20,
  CTRL2             = 0x21,
  CTRL3             = 0x22,
  CTRL4             = 0x23,
  CTRL5             = 0x24,
  CTRL6             = 0x25,
  CTRL7             = 0x26,
  STATUS_A          = 0x27,

  OUT_X_L_A         = 0x28,
  OUT_X_H_A         = 0x29,
  OUT_Y_L_A         = 0x2A,
  OUT_Y_H_A         = 0x2B,
  OUT_Z_L_A         = 0x2C,
  OUT_Z_H_A         = 0x2D,

  FIFO_CTRL         = 0x2E,
  FIFO_SRC          = 0x2F,

  IG_CFG1           = 0x30,
  IG_SRC1           = 0x31,
  IG_THS1           = 0x32,
  IG_DUR1           = 0x33,
  IG_CFG2           = 0x34,
  IG_SRC2           = 0x35,
  IG_THS2           = 0x36,
  IG_DUR2           = 0x37,

  CLICK_CFG         = 0x38,
  CLICK_SRC         = 0x39,
  CLICK_THS         = 0x3A,
  TIME_LIMIT        = 0x3B,
  TIME_LATENCY      = 0x3C,
  TIME_WINDOW       = 0x3D,

  Act_THS           = 0x3E,
  Act_DUR           = 0x3F,
}LSM303_regAddr;


#endif /* LSM303_TYPEDEF_H_ */
