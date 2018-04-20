
/**
 * LS9110S H BRIDGE DRIVER
 * Author: Matheus Castello
 * E-mail: matheus@castello.eng.br
 * Date: 20/04/2018
 **/

#ifndef DCMOTOR_H_
#define DCMOTOR_H_

#include <Arduino.h>

#define DCMOTOR_NO_PROBEB   -1

#define DCMOTOR_DIRECTION_FORWARD   HIGH
#define DCMOTOR_DIRECTION_REVERSE   LOW


struct ls9110s_motor {
    byte    pinA;
    byte    pinB;
    byte    speed;
    bool    direction;
    bool    probed;
};

#endif