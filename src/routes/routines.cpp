#include "main.h"
// movement profile = {0.05, 0, 0.01}
// rotation turn 8000, 0.5, 6000, {0.02, 0, 0.08} 90 deg

void scoring()
{
    motion_profile motionProfile;
    
    /*--Deploy intake--*/
    catapult.moveVoltage(12000);
    pros::delay(125);
    catapult.moveVoltage(0);

    /*--Alliance triball--*/
    pros::delay(200);
    intake.moveVoltage(12000);
    pros::delay(180);
    intake.moveVoltage(0);
    motionProfile.moveDistance(3, 0, 1, {0.02, 0, 0.04}, {25, 0.01, 0.3, 25}); // to not hit bar
    pros::delay(100);
    
    rotationTurn(72, 8000, 1, 1200, {0.02, 0, 0.08}); // get to goal:
    pros::delay(100);
    motionProfile.moveDistance(11.5/*18*/, 72, 1, {0.05, 0, 0.01}, {40, 0.1, 0.3, 3});
    pros::delay(100);
    
    /*--5 Balls--*/
    toggleMatchLoad();
    moveLeftGroup(-12000);
    moveRightGroup(12000);
    pros::delay(500);
    driveGroup.moveVoltage(0);
    toggleMatchLoad();
    motionProfile.moveDistance(6.5/*18*/, 72, 1, {0.05, 0, 0.01}, {40, 0.1, 0.3, 3});
    /*--End--*/

    rotationTurn(45, 8000, 1, 800, {0.02, 0, 0.08}); // pushing triball:
    intake.moveVoltage(-12000);
    pros::delay(500);
    driveGroup.moveVoltage(12000);
    pros::delay(1000);
    driveGroup.moveVoltage(0);
    intake.moveVoltage(0);
    // pros::delay(500);
    motionProfile.moveDistance(-14.5, 45, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});

    /*--Additional triballs--*/

    // pros::delay(500);
    rotationTurn(-22, 8000, 1, 1200, {0.02, 0, 0.08}); // get to first triball:
    // pros::delay(500);
    motionProfile.moveDistance(46, -22, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    intake.moveVoltage(12000);
    pros::delay(200);
    intake.moveVoltage(0);
    motionProfile.moveDistance(-1, 95, 1, {0.02, 0, 0.04}, {25, 0.01, 0.3, 25}); // get triball to goal:
    rotationTurn(95, 8000, 1, 1200, {0.02, 0, 0.08});
    motionProfile.moveDistance(8, 95, 1, {0.02, 0, 0.04}, {25, 0.01, 0.3, 25});
    intake.moveVoltage(-12000);
    pros::delay(500);
    intake.moveVoltage(0);
    motionProfile.moveDistance(-5, 95, 1, {0.02, 0, 0.04}, {25, 0.01, 0.3, 25});
    rotationTurn(20, 8000, 1, 1200, {0.02, 0, 0.08}); // get second and third triball:
    pros::delay(250);
    intake.moveVoltage(12000);
    motionProfile.moveDistance(21.5, 20, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    pros::delay(180);
    intake.moveVoltage(0);
    motionProfile.moveDistance(-7, 20, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    // pros::delay(500);
    rotationTurn(81.5, 8000, 1, 1200, {0.02, 0, 0.08});
    toggleLeftWing(); // open wings
    toggleRightWing();
    motionProfile.moveDistance(12, 81.5, 1, {0.05, 0, 0.01}, {45, 0.01, 0.3, 3});
    rotationTurn(135, 8000, 1, 1200, {0.02, 0, 0.08}); // pushing triballs:
    intake.moveVoltage(-12000);
    pros::delay(300);
    driveGroup.moveVoltage(12000);
    pros::delay(850);
    driveGroup.moveVoltage(-12000);
    pros::delay(300);
    driveGroup.moveVoltage(0);
    intake.moveVoltage(0);
    toggleLeftWing();
    toggleRightWing();
}

// this path is illegal sometimes? also destruction auton works well enough to just not use this path

void winpointAuton()
{
    // setup against wall and matchload bar
    motion_profile motionProfile;

    /*--Deploy intake--*/
    catapult.moveVoltage(12000);
    intake.moveVoltage(12000);
    pros::delay(125);
    catapult.moveVoltage(0);
    pros::delay(180);
    intake.moveVoltage(0);

    /*--Destroy--*/
    motionProfile.moveDistance(24, 0, 1, {0.02, 0, 0.01}, {40, 0.01, 0.3, 3});
    rotationTurn(30, 8000, 1, 1200, {0.02, 0, 0.08});
    motionProfile.moveDistance(20, 30, 1, {0.02, 0, 0.01}, {40, 0.01, 0.3, 3});
    rotationTurn(0, 8000, 1, 1200, {0.02, 0, 0.08});
    motionProfile.moveDistance(4, 0, 1, {0.02, 0, 0.01}, {40, 0.01, 0.3, 3});
    toggleLeftWing();
    rotationTurn(90, 8000, 1, 1200, {0.02, 0, 0.08}); // test
    motionProfile.moveDistance(26, 90, 1, {0.02, 0, 0.01}, {40, 0.01, 0.3, 3}, 1000);
    toggleLeftWing();
    motionProfile.moveDistance(-12, 90, 1, {0.02, 0, 0.01}, {40, 0.01, 0.3, 3});
    rotationTurn(-90, 8000, 1, 1200, {0.02, 0, 0.08});
    motionProfile.moveDistance(7.5, -90, 1, {0.02, 0, 0.01}, {40, 0.01, 0.3, 3}); // alliance triball pushin
    intake.moveVoltage(-12000);
    pros::delay(200);
    driveGroup.moveVoltage(12000);
    pros::delay(700);
    intake.moveVoltage(0);

    /*--Get to matchload area--*/
    motionProfile.moveDistance(-16, -90, 1, {0.02, 0, 0.01}, {40, 0.01, 0.3, 3});
    rotationTurn(-150, 8000, 1, 1200, {0.02, 0, 0.08});
    motionProfile.moveDistance(44.5, -150, 1, {0.02, 0, 0.01}, {40, 0.01, 0.3, 3}); // trying to get the triball out
    // somehow works:
    toggleMatchLoad();
    pros::delay(150);
    driveLeftGroup.moveVoltage(-7500);
    driveRightGroup.moveVoltage(7500);
    pros::delay(725); // flying
    driveLeftGroup.moveVoltage(0);
    driveRightGroup.moveVoltage(0);
    toggleMatchLoad();

    /*--Winpoint ending--*/
    rotationTurn(136.5, 8000, 1, 1200, {0.02, 0, 0.08});
    motionProfile.moveDistance(8, 136.5, 1, {0.02, 0, 0.01}, {40, 0.01, 0.3, 3});
    rotationTurn(90, 8000, 1, 1200, {0.02, 0, 0.08});
    pros::delay(75);
    intake.moveVoltage(-12000);
    driveGroup.moveVoltage(12000);
    pros::delay(665);
    driveGroup.moveVoltage(0);
    intake.moveVoltage(0);

    /*--Destroy ending--*/
//     rotationTurn(30, 8000, 1, 1200, {0.02, 0, 0.08});
//     motionProfile.moveDistance(10, 136.5, 1, {0.02, 0, 0.01}, {30, 0.01, 0.3, 3});
//     rotationTurn(110, 8000, 1, 1200, {0.02, 0, 0.08});
//     motionProfile.moveDistance(6, 110, 1, {0.02, 0, 0.01}, {30, 0.01, 0.3, 3});
}

void destruction()
{
    // setup against wall and matchload bar
    motion_profile motionProfile;

    /*--Deploy intake--*/
    catapult.moveVoltage(12000);
    intake.moveVoltage(12000);
    pros::delay(125);
    catapult.moveVoltage(0);
    pros::delay(180);
    intake.moveVoltage(0);

    /*--Destroy--*/
    motionProfile.moveDistance(24, 0, 1, {0.02, 0, 0.01}, {40, 0.01, 0.3, 3});
    rotationTurn(30, 8000, 1, 1200, {0.02, 0, 0.08});
    motionProfile.moveDistance(20, 30, 1, {0.02, 0, 0.01}, {40, 0.01, 0.3, 3});
    rotationTurn(0, 8000, 1, 1200, {0.02, 0, 0.08});
    motionProfile.moveDistance(4, 0, 1, {0.02, 0, 0.01}, {40, 0.01, 0.3, 3});
    toggleLeftWing();
    rotationTurn(90, 8000, 1, 1200, {0.02, 0, 0.08}); // test
    motionProfile.moveDistance(26, 90, 1, {0.02, 0, 0.01}, {40, 0.01, 0.3, 3}, 1000);
    toggleLeftWing();
    motionProfile.moveDistance(-12, 90, 1, {0.02, 0, 0.01}, {40, 0.01, 0.3, 3});
    rotationTurn(-90, 8000, 1, 1200, {0.02, 0, 0.08});
    motionProfile.moveDistance(7.5, -90, 1, {0.02, 0, 0.01}, {40, 0.01, 0.3, 3}); // alliance triball pushin
    intake.moveVoltage(-12000);
    pros::delay(200);
    driveGroup.moveVoltage(12000);
    pros::delay(700);
    intake.moveVoltage(0);

    /*--Get to matchload area--*/
    motionProfile.moveDistance(-16, -90, 1, {0.02, 0, 0.01}, {40, 0.01, 0.3, 3});
    rotationTurn(-150, 8000, 1, 1200, {0.02, 0, 0.08});
    motionProfile.moveDistance(44.5, -150, 1, {0.02, 0, 0.01}, {40, 0.01, 0.3, 3}); // trying to get the triball out
    // somehow works:
    toggleMatchLoad();
    pros::delay(150);
    driveLeftGroup.moveVoltage(-7500);
    driveRightGroup.moveVoltage(7500);
    pros::delay(725); // flying
    driveLeftGroup.moveVoltage(0);
    driveRightGroup.moveVoltage(0);
    toggleMatchLoad();

    /*--Winpoint ending--*/
    // rotationTurn(136.5, 8000, 1, 1200, {0.02, 0, 0.08});
    // motionProfile.moveDistance(8, 136.5, 1, {0.02, 0, 0.01}, {40, 0.01, 0.3, 3});
    // rotationTurn(90, 8000, 1, 1200, {0.02, 0, 0.08});
    // pros::delay(75);
    // intake.moveVoltage(-12000);
    // driveGroup.moveVoltage(12000);
    // pros::delay(665);
    // driveGroup.moveVoltage(0);
    // intake.moveVoltage(0);

    /*--Destroy ending--*/
    rotationTurn(30, 8000, 1, 1200, {0.02, 0, 0.08});
    motionProfile.moveDistance(10, 136.5, 1, {0.02, 0, 0.01}, {30, 0.01, 0.3, 3});
    rotationTurn(110, 8000, 1, 1200, {0.02, 0, 0.08});
    motionProfile.moveDistance(6, 110, 1, {0.02, 0, 0.01}, {30, 0.01, 0.3, 3});
}
