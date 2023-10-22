#include "main.h"


    // motionProfile.moveDistance(12, 0, 2, {0.04, 0, 0.07}, {40, 0.1, 0.4, 10});




void closeSide(){ // https://www.youtube.com/watch?v=5pNX0Jpspn8 lololol
    motion_profile motionProfile;
    /*
    movement profile = {0.05, 0, 0.01}
	rotation turn 8000, 0.5, 6000, {0.0275, 0, 0.02} 90 deg
	*/
    while(potentiometer.get() < 900){
        catapult.moveVoltage(12000);
    }
    catapult.moveVoltage(0);
    intake.moveVoltage(12000);
    motionProfile.moveDistance(55, 0, 1, {0.05, 0, 0.01}, {40, 0.1, 0.3, 3});
    pros::delay(1000);
    intake.moveVoltage(0);
    rotationTurn(110, 8000, 0.5, 6000, {0.0275, 0, 0.02});
    intake.moveVelocity(-12000);
    pros::delay(1000);
    intake.moveVelocity(12000);
    rotationTurn(-150, 8000, 0.5, 6000, {0.0275, 0, 0.02});
    motionProfile.moveDistance(20, 0, 1, {0.05, 0, 0.01}, {40, 0.1, 0.3, 3});
    pros::delay(1000);
    rotationTurn(100, 8000, 0.5, 6000, {0.0275, 0, 0.02});
}