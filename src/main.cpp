#include "main.h"
int autonNumber = 0;
bool skills = false; //false for regular matches, true for skills
int catapos = 1180;
uint32_t lastPressed = -800;
/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	//pros::lcd::set_text(1, "81208S code ");

	pros::lcd::register_btn1_cb(on_center_button);
	driveGroup.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
	
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
		motion_profile motionProfile;
		// movement profile = {0.05, 0, 0.01}
		// rotation turn 8000, 0.5, 6000, {0.0275, 0, 0.02} 90, 45 deg
		closeSide();
		
		pros::lcd::print(2, "IMU: %f" , getIMU());
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
		updatePneumatics();
		
		//toggle
		if(YButton.changedToPressed()){
			if(skills == false) {
				skills = true;
				catapos = 1100;
			} else {
				skills = false;
				catapos = 1180;
			}
		}

		//Catapult code because the catapult file doesn't work unfortunately.
		//Down Pos: 1180 reg match : 1100 skills
		if (potentiometer.get() < catapos) // catapult automatically goes down to the down position. NOTICE: there is quite a big delay, so it is best if you make the potentiometer value around ~200ish lower than the value you want.
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
