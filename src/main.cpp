#include "main.h"
uint32_t lastPressed = -800;
int autonNumber = 2; // auton selector test.

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
	// while (potentiometer.get() > 700 || potentiometer.get() < 500) //unreliable way for having the cata automatically reset itself hopefully works lmao
	// {
	// 	catapult.moveVoltage(12000);
	// }
	// catapult.moveVoltage(0);
	// while(YButton.isPressed()){
	// 	if(XButton.isPressed()){
	// 		autonNumber++;
	// 	} else if (BButton.isPressed()){
	// 		autonNumber--;
	// 	} else{
	// 		//do nothing
	// 	}
	// 	if(autonNumber < 0){
	// 		autonNumber = 3;
	// 	}
	// 	if(autonNumber > 3){
	// 		autonNumber = 0;
	// 	}
	// 	switch(autonNumber){
	// 		case 0:
    //             controller.rumble(".");
    //             break;
    //         case 1:
    //             controller.rumble("..");
    //             break;
    //         case 2:
    //             controller.rumble("...");
    //             break;
    //         case 3:
    //             controller.rumble("-");
    //             break;
	// 	}
		
	// 	pros::delay(20);
	// }
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
	okapi::ControllerButton fire(okapi::ControllerDigital::R1);
	// controller.rumble("..");
	//master.clear(); testing smth
	while (true)
	{
		// basic chassis control, do not touch.
		driveChassis();
		updateIntake();
		updatePneumatics();
		// opCatapult();

		// Down Pos: 1180
		// NOTICE: there is delay when it comes to updating values, so it is best if you make the potentiometer value around ~200ish lower than the value you want.
		if (potentiometer.get() < 1180)
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
