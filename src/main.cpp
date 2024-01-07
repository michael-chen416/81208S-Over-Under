/* ALL AUTON FILES ARE COMMENTED OUT DUE TO PNEUMATICS*/
/* PNEUMATICS FILES ARE COMMENTED OUT */
/* AUTON RUNNING IS COMMENTED OUT IN MAIN */
/* UPDATE PNEUMATICS IS COMMENTED OUT IN OPCONTROL */

#include "main.h"
uint32_t lastPressed = -800;
int autonNumber = 4;
// 0 = Winpoint
// 1 = Destruction
// 2 = Score 4
// 3 = Score 5
// 4 = Score 6
// 5 = Skills
// 6 = SoloWP
// 7 = Tests

void on_center_button() {}

void initialize()
{
	pros::lcd::initialize();
	gyro.reset();

	pros::lcd::print(2, "Catapult pos: %f", potentiometer.get());
	pros::lcd::print(3, "Yaw: %f", getIMU());
	pros::lcd::register_btn1_cb(on_center_button);
	driveGroup.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
}

void disabled() {}

void competition_initialize() {}

void autonomous()
{
	motion_profile motionProfile;
	switch (autonNumber)
	{
	case 0:
		pros::lcd::set_text(1, "Winpoint");
		winpointAuton();
		break;
	case 1:
		pros::lcd::set_text(1, "Destruction");
		destruction();
		break;
	case 2:
		pros::lcd::set_text(1, "Score 4");
		scoring();
		break;
	case 3:
		pros::lcd::set_text(1, "Score 5");
		scorefive();
		break;
	case 4:
		pros::lcd::set_text(1, "Score 6");
		scoresix();
		break;
	case 5:
		pros::lcd::set_text(1, "SKILLS");
		skills();
		break;
	case 6:
		pros::lcd::set_text(1, "Solo WP");
		soloWP();
		break;
	case 7:
		pros::lcd::set_text(1, "Test");
		tests();
		break;
	}
}

void opcontrol()
{
	pros::Controller master(pros::E_CONTROLLER_MASTER);
	while (true)
	{
		// basic chassis control, do not touch.
		driveChassis();
		updateIntake();
		// updatePneumatics();
		// opCatapult();

		if (r2.changedToPressed())
		{
			cataToggle = !cataToggle;
		}
		// Down Pos: 1180
		// NOTICE: there is delay when it comes to updating values, so it is best if you make the potentiometer value around ~200ish lower than the value you want.
		if (cataToggle)
		{
			catapult.moveVoltage(12000);
		}
		else
		{
			if (potentiometer.get() > 1180) // CHANGE THIS POSITION
			{
				catapult.moveVoltage(12000);
			}
			else if (r1.changedToPressed())
			{
				lastPressed = pros::millis();
				catapult.moveRelative(1000, 12000);
			}
			else if (pros::millis() - lastPressed > 400/*350*/ && r1.isPressed()) //change this value maybe 
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
