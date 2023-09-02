#include "subsystems/drive.hpp"

void driveChassis(){
    double forward = controller.getAnalog(okapi::ControllerAnalog::leftY); // gets the values from the joysticks , -127 - 127
    double turn = controller.getAnalog(okapi::ControllerAnalog::rightX);

    driveLeftGroup.moveVoltage(std::clamp(forward + turn, -1.0, 1.0) * 12000);
    driveRightGroup.moveVoltage(std::clamp(forward - turn, -1.0, 1.0) * 12000);

}