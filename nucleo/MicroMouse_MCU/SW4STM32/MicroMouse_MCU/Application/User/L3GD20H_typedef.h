/*
 * L3GD20H_typedef.h
 *
 *  Created on: 28 sie 2017
 *      Author: Chupacabra
 */

#ifndef L3GD20H_TYPEDEF_H_
#define L3GD20H_TYPEDEF_H_

enum regAddr
    {
       WHO_AM_I       = 0x0F,

       CTRL1          = 0x20, // D20H
       CTRL2          = 0x21, // D20H
       CTRL3          = 0x22, // D20H
       CTRL4          = 0x23, // D20H
       CTRL5          = 0x24, // D20H
       REFERENCE      = 0x25,
       OUT_TEMP       = 0x26,
       STATUS         = 0x27, // D20H

       OUT_X_L        = 0x28,
       OUT_X_H        = 0x29,
       OUT_Y_L        = 0x2A,
       OUT_Y_H        = 0x2B,
       OUT_Z_L        = 0x2C,
       OUT_Z_H        = 0x2D,

       FIFO_CTRL      = 0x2E, // D20H
       FIFO_SRC       = 0x2F, // D20H

       IG_CFG         = 0x30, // D20H
       IG_SRC         = 0x31, // D20H
       INT1_SRC       = 0x31, // D20, 4200D
       IG_THS_XH      = 0x32, // D20H
       INT1_THS_XH    = 0x32, // D20, 4200D
       IG_THS_XL      = 0x33, // D20H
       INT1_THS_XL    = 0x33, // D20, 4200D
       IG_THS_YH      = 0x34, // D20H
       INT1_THS_YH    = 0x34, // D20, 4200D
       IG_THS_YL      = 0x35, // D20H
       INT1_THS_YL    = 0x35, // D20, 4200D
       IG_THS_ZH      = 0x36, // D20H
       INT1_THS_ZH    = 0x36, // D20, 4200D
       IG_THS_ZL      = 0x37, // D20H
       INT1_THS_ZL    = 0x37, // D20, 4200D
       IG_DURATION    = 0x38, // D20H
       INT1_DURATION  = 0x38, // D20, 4200D

       LOW_ODR        = 0x39  // D20H
    };


#endif /* L3GD20H_TYPEDEF_H_ */
