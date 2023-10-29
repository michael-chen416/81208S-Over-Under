#include "main.h"
// movement profile = {0.05, 0, 0.01}
// rotation turn 8000, 0.5, 6000, {0.0275, 0, 0.02} 90 deg

void closeWinPoint(){
    motion_profile motionProfile;
    
    //getting matchload ball out + aligning with side 
    motionProfile.moveDistance(10, 0, 1, {0.05, 0, 0.01}, {40, 0.1, 0.3, 3});
    extendMatchload();
    pros::delay(1000);
    motionProfile.moveDistance(-5, 0, 1, {0.05, 0, 0.01}, {40, 0.1, 0.3, 3});
    pros::delay(1000);
	rotationTurn(80, 8000, 0.5, 6000, {0.0275, 0, 0.02});
    pros::delay(1000);
    retractMatchload();
    motionProfile.moveDistance(22, 80, 1, {0.05, 0, 0.01}, {40, 0.1, 0.3, 3});
    pros::delay(500);
    //putting alliance triball in net
    rotationTurn(45, 8000, 0.5, 6000, {0.0275, 0, 0.02});
    motionProfile.moveDistance(-3, 45, 1, {0.05, 0, 0.05}, {40, 0.1, 0.3, 3});
    intake.moveVoltage(-12000); 
    pros::delay(500);
    rotationTurn(-90, 8000, 0.5, 6000, {0.0275, 0, 0.02}); //turns around to push the triball into the net
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
}

void farWinPoint(){

}

void closeSide(){
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

void farSide(){
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
// rotationTurn(90, 8000, 0.5, 1200, {0.0175, 0, 0.02});
//     pros::delay(3000);
// rotationTurn(135, 8000, 0.5, 1200, {0.015, 0, 0.02});
//     pros::delay(3000);
// rotationTurn(70, 8000, 0.5, 1200, {0.0175, 0, 0.02});
//     pros::delay(3000);
// rotationTurn(-20, 8000, 0.5, 1200, {0.015, 0, 0.02});

    // motionProfile.moveDistance(-3, 0, 1, {0.02, 0, 0.04}, {25, 0.01, 0.3, 25});
    // pros::delay(10);
    // rotationTurn(95, 8000, 0.5, 1200, {0.0175, 0, 0.02});
    // motionProfile.moveDistance(18, 95, 1, {0.02, 0, 0.01}, {40, 0.01, 0.3, 3});
    // rotationTurn(132, 8000, 0.5, 1200, {0.0275, 0, 0.02});
    // intake.moveVoltage(-12000);
    // pros::delay(1500);
    // intake.moveVoltage(0);
    // motionProfile.moveDistance(8, 132, 1, {0.05, 0, 0.01}, {30, 0.01, 0.3, 30});//no greater than 9 no less than 8.5
    // motionProfile.moveDistance(-15, 132, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    // //extend matchload bar here!
    // pros::delay(3000);
    // 131
    // angleOffset = 132;
    rotationTurn(245, 7200, 1, 5500, {0.01, 0, 0.02});
    // -131
    // pros::delay(3000);
    // motionProfile.moveDistance(28, 260, 1, {0.05, 0, 0.01}, {40, 0.1, 0.3, 3}, 700);
    // pros::delay(10000);
    // rotationTurn(225, 8000, 0.5, 7000, {0.0275, 0, 0.02});
    // pros::delay(2000);
    // motionProfile.moveDistance(35, 225, 1, {0.05, 0, 0.01}, {40, 0.1, 0.3, 3});
    // pros::delay(2000);
}
