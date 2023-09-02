#include "main.h"

void updateIntake(){
    okapi::ControllerButton intakeButton(okapi::ControllerDigital::L1);
    okapi::ControllerButton outtakeButton(okapi::ControllerDigital::L2);

    if(intakeButton.isPressed()){
        intake.moveVoltage(12000);
    } 
    else if (outtakeButton.isPressed()){
        intake.moveVoltage(-12000);
    } else {
        intake.moveVoltage(0);
    }
}