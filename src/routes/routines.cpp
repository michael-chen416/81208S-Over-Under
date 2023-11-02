#include "main.h"
// movement profile = {0.05, 0, 0.01}
// rotation turn 8000, 0.5, 6000, {0.0275, 0, 0.02} 90 deg


void farWinPoint(){

}

void closeSide(){
    motion_profile motionProfile;

    /*--Alliance triball--*/
    
    motionProfile.moveDistance(3, 0, 1, {0.02, 0, 0.04}, {25, 0.01, 0.3, 25});
    pros::delay(250);
    rotationTurn(72, 8000, 1, 1200, {0.02, 0, 0.08});
    pros::delay(250);
    motionProfile.moveDistance(18, 72, 1, {0.05, 0, 0.01}, {40, 0.1, 0.3, 3});
    pros::delay(500);
    rotationTurn(45, 8000, 1, 1200, {0.02, 0, 0.08});
    intake.moveVoltage(-12000);
    pros::delay(1000);
    motionProfile.moveDistance(12.5, 45, 1, {0.05, 0, 0.01}, {30, 0.01, 0.3, 30});
    intake.moveVoltage(0);
    // pros::delay(500);
    motionProfile.moveDistance(-15, 45, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});

    /*--Additional triballs--*/ 

    // pros::delay(500);
    rotationTurn(-22, 8000, 1, 1200, {0.02, 0, 0.08});
    // pros::delay(500);
    motionProfile.moveDistance(45, -22, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    intake.moveVoltage(12000);
    pros::delay(500);
    intake.moveVoltage(0); // first triball
    rotationTurn(92, 8000, 1, 1200, {0.02, 0, 0.08});
    pros::delay(250);
    intake.moveVoltage(-12000);
    pros::delay(250);
    intake.moveVoltage(0);
    motionProfile.moveDistance(3, 92, 1, {0.02, 0, 0.04}, {25, 0.01, 0.3, 25});
    rotationTurn(20, 8000, 1, 1200, {0.02, 0, 0.08});
    pros::delay(250);
    intake.moveVoltage(12000);
    motionProfile.moveDistance(24, 20, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    pros::delay(250);
    intake.moveVoltage(0);
    // pros::delay(500);
    rotationTurn(135, 8000, 1, 1200, {0.02, 0, 0.08});
    toggleLeftWing(); //open wings
    toggleRightWing();
    // pros::delay(500);
    intake.moveVoltage(-12000);
    motionProfile.moveDistance(27, 135, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3}); // pushing the triball
    // pros::delay(500);
    intake.moveVoltage(0);
    motionProfile.moveDistance(-16, 135, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    toggleLeftWing();
    toggleRightWing();

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

    motionProfile.moveDistance(-3, 0, 1, {0.02, 0, 0.04}, {25, 0.01, 0.3, 25});
    rotationTurn(95, 8000, 1, 1200, {0.02, 0, 0.08});
    motionProfile.moveDistance(14, 95, 1, {0.02, 0, 0.01}, {40, 0.01, 0.3, 3});
    rotationTurn(132, 8000, 1, 1200, {0.02, 0, 0.08});
    intake.moveVoltage(-12000);
    pros::delay(1000);
    intake.moveVoltage(0);
    motionProfile.moveDistance(9, 132, 1, {0.05, 0, 0.01}, {30, 0.01, 0.3, 30});//no greater than 9 no less than 8.5
    motionProfile.moveDistance(-16, 132, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    //extend matchload bar here!
    // 131
    // angleOffset = 132;
    // rotationTurn(245, 7200, 1, 5500, {0.01, 0, 0.02});
    // -131
    rotationTurn(180, 8000, 1, 1200, {0.02, 0, 0.08});
    driveLeftGroup.moveVoltage(8000);
    driveRightGroup.moveVoltage(-8000);
    pros::delay(200);
    driveLeftGroup.moveVoltage(0);
    driveRightGroup.moveVoltage(0);
    pros::delay(1500);
    rotationTurn(-95, 8000, 1, 1500, {0.02, 0, 0.08});
    motionProfile.moveDistance(15.5, -95, 1, {0.05, 0, 0.01}, {40, 0.1, 0.3, 3});
    rotationTurn(-135, 8000, 1, 1500, {0.02, 0, 0.08});
    motionProfile.moveDistance(40, -135, 1, {0.05, 0, 0.01}, {40, 0.1, 0.3, 3});
    // pros::delay(2000);
    
    //old
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
    // // 131
    // // angleOffset = 132;
    // // rotationTurn(245, 7200, 1, 5500, {0.01, 0, 0.02});
    // // -131
    // pros::delay(3000);
    // motionProfile.moveDistance(28, 260, 1, {0.05, 0, 0.01}, {40, 0.1, 0.3, 3}, 700);
    // pros::delay(10000);
    // rotationTurn(225, 8000, 0.5, 7000, {0.0275, 0, 0.02});
    // pros::delay(2000);
    // motionProfile.moveDistance(35, 225, 1, {0.05, 0, 0.01}, {40, 0.1, 0.3, 3});
}

void skills(){
    // movement profile = {0.05, 0, 0.01}
    //rotation turn 8000, 0.5, 6000, {0.02, 0, 0.08} 90 deg
}