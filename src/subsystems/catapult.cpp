#include "subsystems/catapult.hpp"
uint32_t lastPressed = -800;
/*NOTICE*/

//The actual code is in main, I just left this here so that in the unlikely case that this file works again, I don't have to go through the hassle of bringing everything back

void OpCatapult() {
    okapi::ControllerButton fire(okapi::ControllerDigital::R1);
    if (potentiometer.get() < 1281) 
		{ 
			catapult.moveVoltage(12000);
		}
		else if (fire.changedToPressed())
		{
			lastPressed = pros::millis();
			catapult.moveRelative(3000, 12000);
		}
		else if (pros::millis() - lastPressed > 350 && fire.isPressed())
		{
			catapult.moveVoltage(12000);
		}
		else
		{
			catapult.moveVoltage(0);
		}
}