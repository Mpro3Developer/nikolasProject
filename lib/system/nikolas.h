
/**
 * Nikolas Line Follow Robot
 * Author: Matheus Castello
 * E-mail: matheus@castello.eng.br
 * Date: 20/04/2018
 **/

#ifndef NIKOLAS_H_
#define NIKOLAS_H_

#include <nikolas_defconfig.h>
#include <l9110s.h>
#include <tcrt5000.h>

static void nikolas_init_left_motor (ls9110s_motor* motor) {
    motor->pinA = CONFIG_LEFT_MOTOR_PWM_PINA;
    motor->pinB = CONFIG_LEFT_MOTOR_PINB;
    motor->direction = CONFIG_LEFT_MOTOR_INITIAL_DIRECTION;
    motor->speed = CONFIG_LEFT_MOTOR_INITIAL_SPEED;

    ls9110s_probe(motor);
}

static void nikolas_init_right_motor (ls9110s_motor* motor) {
    motor->pinA = CONFIG_RIGHT_MOTOR_PWM_PINA;
    motor->pinB = CONFIG_RIGHT_MOTOR_PINB;
    motor->direction = CONFIG_RIGHT_MOTOR_INITIAL_DIRECTION;
    motor->speed = CONFIG_RIGHT_MOTOR_INITIAL_SPEED;

    ls9110s_probe(motor);
}

static void nikolas_init_line_follow_sensors (tcrt5000_controller* sensors) {
    sensors->pin1 = CONFIG_LINE_FOLLOW_SENSOR_RIGHT;
    sensors->pin2 = CONFIG_LINE_FOLLOW_ANALOG_CENTER_RIGHT;
    sensors->pin3 = CONFIG_LINE_FOLLOW_ANALOG_CENTER_LEFT;
    sensors->pin4 = CONFIG_LINE_FOLLOW_ANALOG_LEFT;

    tcrt5000_probe(sensors);
}

#endif