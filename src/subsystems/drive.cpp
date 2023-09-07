#include "subsystems/drive.hpp"

void driveChassis(){
    double forward = controller.getAnalog(okapi::ControllerAnalog::leftY);// forward + backwards
    double turn = controller.getAnalog(okapi::ControllerAnalog::rightX);// left + right

    driveLeftGroup.moveVoltage(std::clamp(forward + turn, -1.0, 1.0) * 12000);
    driveRightGroup.moveVoltage(std::clamp(forward - turn, -1.0, 1.0) * 12000);

    // clamp -> if the value is not in range -> "clamps it"
    // max is 127, 128 -> 127 
    // min is -127 , -200 -> -127 
    // max 1, joystick results is 2, -> 1 
}