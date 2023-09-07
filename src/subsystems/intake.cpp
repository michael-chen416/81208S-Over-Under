#include "main.h"

void updateIntake() {
  okapi::ControllerButton intakeButton(okapi::ControllerDigital::L1);
  okapi::ControllerButton outtakeButton(okapi::ControllerDigital::L2);

  if (intakeButton.isPressed()) {  // If the intake button is pressed, move the intake motor group forward, if outtake, reverse it.
    intake.moveVoltage(12000);
  } else if (outtakeButton.isPressed()) {  // Same process as intake, but instead, reverse the direction of the intake motor group.
    intake.moveVoltage(-12000);
  } else {
    intake.moveVoltage(0);
  }
}