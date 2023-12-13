#include "main.h"

void updateIntake()
{
  //meh ill just put the code explination here
  //We check whether if the user is pressing the r1 or r2 button
  //r1 is intake, r2 is outtake
  //if r1, for example, is pressed, it runs to the intake at full speed, same principal for r2
  //otherwise, don't move the intake.
  okapi::ControllerButton intakeButton(okapi::ControllerDigital::L1);
  okapi::ControllerButton outtakeButton(okapi::ControllerDigital::L2);

  if (intakeButton.isPressed())
  { 
    intake.moveVoltage(12000);
  }
  else if (outtakeButton.isPressed())
  { 
    intake.moveVoltage(-12000);
  }
  else
  {
    intake.moveVoltage(0);
  }
}

void progIntake()
{ // fix
  uint32_t timeout = pros::millis();
  intake.moveRelative(-40, -6000);
  pros::delay(75);
  intake.moveVoltage(0);
}