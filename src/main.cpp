#include "main.h"
int autonNumber = 0;
uint32_t lastPressed = -800;
/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "81208S code ");

	pros::lcd::register_btn1_cb(on_center_button);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() { 
switch(autonNumber){
		case 0:
			pros::lcd::set_text(1, "Auton Path 1");
			// winPointAuton();
			closeSide();
			break;
		case 1:
			pros::lcd::set_text(1, "Auton Path 2");
			//code here
			
			break;
		case 2:
			pros::lcd::set_text(1, "Auton Path 3");
			//code here
			
			break;
		case 3:
			pros::lcd::set_text(1, "Auton Path 4");
			//code here
			
			break;
		case 4:
			pros::lcd::set_text(1, "Skills");
			//code here
			
			break;
	}
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol()
{
	pros::Controller master(pros::E_CONTROLLER_MASTER);
	okapi::ControllerButton fire(okapi::ControllerDigital::R1);

	while (true)
	{
		pros::lcd::print(5, "potentiometer value: %f", potentiometer.get());
		driveChassis();
		updateIntake();
		//Catapult code because the catapult file doesn't work unfortunately.
		//Down Pos: 1480
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
		pros::delay(20);
	}
}
