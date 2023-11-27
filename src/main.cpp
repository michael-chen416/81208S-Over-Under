#include "main.h"
uint32_t lastPressed = -800;
int autonNumber = 1; // auton selector test.

void on_center_button() {}

void initialize()
{
	pros::lcd::initialize();
	matchloadBar.set_value(true);
	gyro.reset();
	pros::lcd::print(2, "Catapult pos: %f", potentiometer.get());
	pros::lcd::print(2, "Yaw: %f", getIMU());
	pros::lcd::register_btn1_cb(on_center_button);
	driveGroup.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);

	/* new auton selector hope it works */
	// bool exit = true;
	while (true)
	{ // og exit
		if (XButton.changedToPressed())
		{
			autonNumber++;
			autonNumber = (autonNumber + 4) % 4; // remember to change this when adding new paths
		}
		else if (BButton.changedToPressed())
		{
			autonNumber--;
			autonNumber = (autonNumber + 4) % 4; // remember to change this when adding new paths
		}
		if (YButton.changedToPressed())
		{
			switch (autonNumber)
			{
			case 0:
				controller.rumble("-");
				break;
			case 1:
				controller.rumble(". .");
				break;
			case 2:
				controller.rumble("- - -");
				break;
			case 3:
				controller.rumble("- . - .");
				break;
			default:									// this should never run
				controller.rumble(". . . - - - . . ."); // haha sos bro the controllers battery is gonna be nonexistant after this one. well it shouldnt happen anyways
				break;
			}
		}
		if (AButton.changedToPressed())
		{
			// exit = false;
			break;
		}
		pros::delay(20);
	}
}

void disabled() {}

void competition_initialize() {}

void autonomous()
{
	motion_profile motionProfile;
	switch (autonNumber)
	{
	case 0:
		pros::lcd::set_text(1, "WinPoint_1");
		winpointAuton();
		break;
	case 1:
		pros::lcd::set_text(1, "Scoring");
		scoring();
		break;
	case 2:
		pros::lcd::set_text(1, "Destruction");
		destruction();
		break;
	case 3:
		pros::lcd::set_text(1, "SKILLS");
		skills();
		break;
	}
}

void opcontrol()
{
	pros::Controller master(pros::E_CONTROLLER_MASTER);
	// okapi::ControllerButton fire(okapi::ControllerDigital::R1);
	// okapi::ControllerButton cToggle(okapi::ControllerDigital::up); experimental, possible doesn't work
	while (true)
	{
		// basic chassis control, do not touch.
		driveChassis();
		updateIntake();
		updatePneumatics();
		if (r2.changedToPressed())
		{
			cataToggle = !cataToggle;
		}
		// Down Pos: 1180
		// NOTICE: there is delay when it comes to updating values, so it is best if you make the potentiometer value around ~200ish lower than the value you want.
		if (cataToggle)
		{
			catapult.moveVoltage(0);
		}
		else
		{
			if (potentiometer.get() < 1180)
			{
				catapult.moveVoltage(12000);
			}
			else if (r1.changedToPressed())
			{
				lastPressed = pros::millis();
				catapult.moveRelative(1000, 12000);
			}
			else if (pros::millis() - lastPressed > 350 && r1.isPressed())
			{
				catapult.moveVoltage(12000);
			}
			else
			{
				catapult.moveVoltage(0);
			}
		}
		pros::delay(20);
	}
}
