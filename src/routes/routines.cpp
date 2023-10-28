#include "main.h"
// movement profile = {0.05, 0, 0.01}
// rotation turn 8000, 0.5, 6000, {0.0275, 0, 0.02} 90 deg

     void closeSide(){
    motion_profile motionProfile;
    
    motionProfile.moveDistance(10, 0, 1, {0.05, 0, 0.01}, {40, 0.1, 0.3, 3});
    extendMatchload();
    pros::delay(1000);
    motionProfile.moveDistance(-5, 0, 1, {0.05, 0, 0.01}, {40, 0.1, 0.3, 3});
    pros::delay(1000);
	rotationTurn(80, 8000, 0.5, 6000, {0.0275, 0, 0.02});
    pros::delay(1000);
    retractMatchload();
    motionProfile.moveDistance(22, 80, 1, {0.05, 0, 0.01}, {40, 0.1, 0.3, 3});
    //getting matchload ball out
    pros::delay(500);
    rotationTurn(45, 8000, 0.5, 6000, {0.0275, 0, 0.02});
    motionProfile.moveDistance(-3, 45, 1, {0.05, 0, 0.05}, {40, 0.1, 0.3, 3});
    intake.moveVoltage(-12000); //outtake
    pros::delay(500);
    rotationTurn(-90, 8000, 0.5, 6000, {0.0275, 0, 0.02});
    pros::delay(500);
    motionProfile.moveDistance(-5, 45, 1, {0.05, 0, 0.05}, {40, 0.1, 0.3, 3});
    pros::delay(1000);
    motionProfile.moveDistance(5, 45, 1, {0.05, 0, 0.01}, {40, 0.1, 0.3, 3});
    pros::delay(1000);
    //getting alliance triball in the goal
    rotationTurn(-80, 8000, 0.5, 6000, {0.0275, 0, 0.02});
    
    pros::delay(500);
    motionProfile.moveDistance(25, -80, 1, {0.05, 0, 0.01}, {40, 0.1, 0.3, 3});
    pros::delay(500);
    rotationTurn(-45, 8000, 0.5, 6000, {0.0275, 0, 0.02});
    pros::delay(500);
    motionProfile.moveDistance(20, -80, 1, {0.05, 0, 0.01}, {40, 0.1, 0.3, 3});


    // while(potentiometer.get() < 900){
    //     catapult.moveVoltage(12000);
    // }
    // catapult.moveVoltage(0);
//experimental
    // intake.moveVoltage(12000);
    // motionProfile.moveDistance(55, 0, 1, {0.05, 0, 0.01}, {40, 0.1, 0.3, 3});

    // pros::delay(1000);
    // intake.moveVoltage(0);
    // rotationTurn(110, 8000, 0.5, 6000, {0.0275, 0, 0.02});
    // intake.moveVelocity(-12000);
    // pros::delay(1000);
    // intake.moveVelocity(12000);
    // rotationTurn(-150, 8000, 0.5, 6000, {0.0275, 0, 0.02});
    // motionProfile.moveDistance(20, 0, 1, {0.05, 0, 0.01}, {40, 0.1, 0.3, 3});
    // pros::delay(1000);
    // rotationTurn(100, 8000, 0.5, 6000, {0.0275, 0, 0.02});
}

void experimental(){
    motion_profile motionProfile;
    /*
    movement profile = {0.05, 0, 0.01}
    rotation turn 8000, 0.5, 6000, {0.0275, 0, 0.02} 90 deg

    115d 
    24f 
    135d
    5f
    5b
    11b
    -105d
    30f
    -135d
    30f
    */
    // while(potentiometer.get() < 900){
    //     catapult.moveVoltage(12000);
    // }
    motionProfile.moveDistance(-4, 0, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    rotationTurn(100, 8000, 0.5, 6000, {0.0275, 0, 0.02});
    motionProfile.moveDistance(19, 100, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    rotationTurn(132, 8000, 0.5, 6000, {0.0275, 0, 0.02});
    intake.moveVoltage(-12000);
    pros::delay(1500);
    intake.moveVoltage(0);
    motionProfile.moveDistance(8.5, 132, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});//8.5
    motionProfile.moveDistance(-9, 132, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    // motionProfile.moveDistance(-11, 132, 1, {0.05, 0, 0.01}, {40, 0.1, 0.3, 3});
    // pros::delay(2000);
    // rotationTurn(-105, 8000, 0.5, 6000, {0.0275, 0, 0.02});
    // pros::delay(2000);
    // motionProfile.moveDistance(30, -105, 1, {0.05, 0, 0.01}, {40, 0.1, 0.3, 3});
    // pros::delay(2000);
    // rotationTurn(-135, 8000, 0.5, 6000, {0.0275, 0, 0.02});
    // pros::delay(2000);
    // motionProfile.moveDistance(30, -135, 1, {0.05, 0, 0.01}, {40, 0.1, 0.3, 3});
    // pros::delay(2000);
}
