#include "main.h"
int autonNumber = 0;
// bool skills = false; // haha this doesn't matter!
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
void initialize()
{
	pros::lcd::initialize();
	// display data and whatnot
	pros::lcd::print(2, "Catapult pos: %f", potentiometer.get());
	pros::lcd::print(2, "Yaw: %f", getIMU());
	pros::lcd::print(3, "Left current: %f", getAverageLeftRotation());
	pros::lcd::print(4, "Right current: %f", getAverageRightRotation());
	// pros::lcd::print(5, "Distance remaining: %f", distanceRemaining);
	// pros::lcd::print(6, "Distance traveled: %f", distanceTraveled);

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
void autonomous()
{
	motion_profile motionProfile;
	// farSide();
	closeWinPoint();
 	//rotationTurn(90, 8000, 1, 1200, {0.02, 0, 0.08}); //.0175, 0, 0.02
	// rotationTurn(90, 8000, 1, 1200, {0.019, 0, 0.08});
    //   pros::delay(3000);
    // rotationTurn(135, 8000, 0.5, 1200, {0.019, 0, 0.08});
    //   pros::delay(3000);
  	// rotationTurn(70, 8000, 0.5, 1200, {0.019, 0, 0.08});
    // 	pros::delay(3000);
 	// rotationTurn(-20, 8000, 0.5, 1200, {0.019, 0, 0.08});
	// pros::lcd::print(2, "IMU: %f", getIMU());
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

		driveChassis();
		updateIntake();
		updatePneumatics();

		// toggle
		if (YButton.changedToPressed())
		{
			// if (skills == false)
			// {
			// 	skills = true;
			// 	catapos = 1100;
			// }
			// else
			// {
			// 	skills = false;
			// 	catapos = 1180;
			// }
		}

		// Down Pos: 1180 reg match : 1100 skills
		if (potentiometer.get() < catapos) // NOTICE: there is delay when it comes to updating values, so it is best if you make the potentiometer value around ~200ish lower than the value you want.
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
