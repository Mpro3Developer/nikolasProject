
/**
 * TCRT5000 4 INFRARED PHOTO SENSOR CONTROLLER
 * Author: Matheus Castello
 * E-mail: matheus@castello.eng.br
 * Date: 20/04/2018
 **/

#ifndef TCRT5000_H_
#define TCRT5000_H_

#include <Arduino.h>

#define TCRT500_NO_PROBED -1
#define TCRT500_SENSOR_NUMBER_FAIL -2

struct tcrt5000_controller {
    /* pin mux analog input */
    byte        pin1;
    byte        pin2;
    byte        pin3;
    byte        pin4;
    /* values */
    uint16_t    out1;
    uint16_t    out2;
    uint16_t    out3;
    uint16_t    out4;
    /* check if the controller is already pin selected */
    bool        probed;
};

static void tcrt5000_probe (tcrt5000_controller* controller) {
    /* TODO put this without pull up for probe sanit sensor */
    pinMode(controller->pin1, INPUT_PULLUP);
    pinMode(controller->pin2, INPUT_PULLUP);
    pinMode(controller->pin3, INPUT_PULLUP);
    pinMode(controller->pin4, INPUT_PULLUP);

    controller->probed = 1;
}

static int tcrt5000_read_all (tcrt5000_controller* controller) {
    if (controller->probed) {
        controller->out1 = analogRead(controller->pin1);
        controller->out2 = analogRead(controller->pin2);
        controller->out3 = analogRead(controller->pin3);
        controller->out4 = analogRead(controller->pin4);

        return 0;
    }

    return TCRT500_NO_PROBED;
}

static int tcrt5000_read (tcrt5000_controller* controller, byte sensor) {
    if (controller->probed) {
        switch (sensor) {
            case 1:
                controller->out1 = analogRead(controller->pin1);
                return controller->out1;                
                break;
            case 2:
                controller->out2 = analogRead(controller->pin2);
                return controller->out2;                
                break;
            case 3:
                controller->out3 = analogRead(controller->pin3);
                return controller->out3;
                break;
            case 4:
                controller->out4 = analogRead(controller->pin4);
                return controller->out4;
                break;
            default:
                return TCRT500_SENSOR_NUMBER_FAIL;
                break;
        }
    }

    return TCRT500_NO_PROBED;
}

#ifdef CONFIG_TCRT5000_DIGITAL_STATE

static bool tcrt5000_digital_state (tcrt5000_controller* controller, byte sensor) {
    if (controller->probed) {
        switch (sensor) {
            case 1:
                return tcrt5000_check_digital_state(controller->out1);               
                break;
            case 2:
                return tcrt5000_check_digital_state(controller->out2);               
                break;
            case 3:
                return tcrt5000_check_digital_state(controller->out3);
                break;
            case 4:
                return tcrt5000_check_digital_state(controller->out4);
                break;
            default:
                return TCRT500_SENSOR_NUMBER_FAIL;
                break;
        }
    }

    return TCRT500_NO_PROBED;
}

bool tcrt5000_check_digital_state (uint16_t value) {
    return value > CONFIG_TCRT5000_DIGITAL_STATE; 
}

#endif

/* TODO function to debug strutcs */

#endif