
/**
 * LS9110S H BRIDGE DRIVER
 * Author: Matheus Castello
 * E-mail: matheus@castello.eng.br
 * Date: 20/04/2018
 **/

#ifndef LS9110S_H_
#define LS9110S_H_

#include <Arduino.h>
#include <dcmotor.h>

static void ls9110s_probe (ls9110s_motor* motor) {
    /* define as output pinA PWM speed */
    pinMode(motor->pinA, OUTPUT);
    /* define as output pinB motor direction */
    pinMode(motor->pinB, OUTPUT);

    /* init with low */
    digitalWrite(motor->pinA, LOW);
    digitalWrite(motor->pinB, LOW);

    motor->probed = 1;
}

static int ls9110s_init (ls9110s_motor* motor) {
    if (motor->probed) {
        analogWrite(motor->pinA, 255 - motor->speed);
        digitalWrite(motor->pinB, motor->direction);
        return 0;
    }

    return DCMOTOR_NO_PROBEB;
}

static int ls9110s_change_speed (ls9110s_motor* motor, byte speed) {
    if (motor->probed) {
        motor->speed = speed;
        digitalWrite(motor->pinB, motor->direction);
        analogWrite(motor->pinA, 255 - motor->speed);
        return 0;
    }

    return DCMOTOR_NO_PROBEB;
}

static int ls9110s_change_direction (ls9110s_motor* motor, bool direction) {
    if (motor->probed) {
        motor->direction = direction;
        digitalWrite(motor->pinB, motor->direction);
        analogWrite(motor->pinA, 255 - motor->speed);
        return 0;
    }

    return DCMOTOR_NO_PROBEB;
}

static int ls9110s_soft_stop (ls9110s_motor* motor) {
    if (motor->probed) {
        digitalWrite(motor->pinA, LOW);
        digitalWrite(motor->pinB, LOW);
        return 0;
    }

    return DCMOTOR_NO_PROBEB;
}

static int ls9110s_hard_stop (ls9110s_motor motor) {
    if (motor.probed) {
        digitalWrite(motor.pinA, HIGH);
        digitalWrite(motor.pinB, HIGH);
        return 0;
    }

    return DCMOTOR_NO_PROBEB;
}

#ifdef CONFIG_DEBUG

static void ls9110s_debug_motor (ls9110s_motor motor) {
    Serial.println("{");

    Serial.println("\tPINA: " + (motor.pinA ? (String) motor.pinA : "null"));
    Serial.println("\tPINB: " + (motor.pinB ? (String) motor.pinB : "null"));
    Serial.println("\tDIRECTION: " + (String) motor.direction);
    Serial.println("\tSPEED: " + (motor.speed ? (String) motor.speed : "null"));
    Serial.println("\tPROBED: " + (motor.probed ? (String) motor.probed : "null"));

    Serial.println("\n}");
}

#endif

#endif