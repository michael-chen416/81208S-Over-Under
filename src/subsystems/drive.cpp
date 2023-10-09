#include "subsystems/drive.hpp"

void moveLeftGroup(double power){
        driveLeftGroup.moveVoltage(power);
}

/**
 * @brief drives the right drive train, adjusts for 4m or 6m depending on pto state
 * 
 * @param power millivolts from -12000 to 12000
 */

void moveRightGroup(double power){
        driveRightGroup.moveVoltage(power);
}

void driveChassis(){
    double forward = controller.getAnalog(okapi::ControllerAnalog::leftY);// forward + backwards
    double turn = controller.getAnalog(okapi::ControllerAnalog::rightX);// left + right

    moveLeftGroup(std::clamp(forward + turn, -1.0, 1.0) * 12000);
    moveRightGroup(std::clamp(forward - turn, -1.0, 1.0) * 12000);

    // clamp -> if the value is not in range -> "clamps it"
    // max is 127, 128 -> 127 
    // min is -127 , -200 -> -127 
    // max 1, joystick results is 2, -> 1 
}