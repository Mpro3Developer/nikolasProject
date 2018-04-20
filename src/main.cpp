#include <Arduino.h>
#include <nikolas.h>
#include <fuzzy_controll.h>

ls9110s_motor leftMotorData;
ls9110s_motor rightMotorData;
tcrt5000_controller lineFollowData;
FunctionBlock_Nikolas_motor_speed Nikolas_motor_speed;

void setup() {
    /* init data and probe */
    nikolas_init_left_motor(&leftMotorData);
    nikolas_init_right_motor(&rightMotorData);
    nikolas_init_line_follow_sensors(&lineFollowData);
    /*Nikolas_motor_speed = new FunctionBlock_Nikolas_motor_speed();*/
    pinMode(13, OUTPUT);

    //Serial.begin(57600);
}

void loop() {
    /* read sensors */
    tcrt5000_read_all (&lineFollowData);

    /*Nikolas_motor_speed->left_midle_sensor = lineFollowData.out3;
    Nikolas_motor_speed->left_sensor = lineFollowData.out4;
    Nikolas_motor_speed->right_middle_sensor = lineFollowData.out2;
    Nikolas_motor_speed->right_sensor = lineFollowData.out1;*/

    /*Nikolas_motor_speed->calc();*/

    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
    delay(1000);
}
