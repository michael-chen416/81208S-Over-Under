#include "subsystems/catapult.hpp"
    uint32_t lastPressed = -800;
	okapi::ControllerButton fire(okapi::ControllerDigital::R1);
/*NOTICE*/
//CODE IS IN MAIN!!!
//GO THERE IF YOU WANT TO FIX THE CATA CODE!!!
void OpCatapult() {
    if (potentiometer.get() < 1240) // catapult automatically goes down to the down position. NOTICE: there is quite a big delay, so it is best if you make the potentiometer value around ~200ish lower than the value you want.
		{ 
			catapult.moveVoltage(12000);
		}
		else if (fire.changedToPressed())
		{
			lastPressed = pros::millis();
			catapult.moveRelative(1000, 12000);
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