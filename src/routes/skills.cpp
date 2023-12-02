#include "main.h"

void skills()
{ // DO NOT DRY FIRE also gyro is acting up 

    motion_profile motionProfile;

    // normal setup
    // outtake while pushing front

    // /*--Deploy intake--*/
    // catapult.moveVoltage(12000);
    // pros::delay(125);
    // catapult.moveVoltage(0);
    
    // /*--Catapult--*/
    // motionProfile.moveDistance(11, 0, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    // rotationTurn(-90, 8000, 1, 1000, {0.02, 0, 0.08});
    // motionProfile.moveDistance(12, -90, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    // rotationTurn(-98, 8000, 1, 1000, {0.02, 0, 0.08});
    // motionProfile.moveDistance(5.5, -98, 1, {0.05, 0, 0.01}, {20, 0.01, 0.3, 3}, 750);
    // catapult.moveVoltage(12000);
    // pros::delay(42000);
    // catapult.moveVoltage(0);

    // /*--Get alliance triball and get to other side--*/
    // motionProfile.moveDistance(-8, -102, 1, {0.05, 0, 0.01}, {20, 0.01, 0.3, 3});
    // catapult.moveVoltage(12000);
    // rotationTurn(-45, 8000, 1, 1000, {0.02, 0, 0.08});
    // catapult.moveVoltage(0);
    // intake.moveVoltage(12000);
    // motionProfile.moveDistance(14, -45, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    // pros::delay(150);
    // intake.moveVoltage(0);
    // motionProfile.moveDistance(-29.5, -45, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    // rotationTurn(-90, 8000, 1, 1000, {0.02, 0, 0.08});
    // motionProfile.moveDistance(-77, -90, 1, {0.05, 0, 0.01}, {40, 0.1, 0.3, 3});

    // /*--Get to center--*/
    // rotationTurn(-135, 8000, 1, 1000, {0.02, 0, 0.08});
    // motionProfile.moveDistance(-12, -135, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    // rotationTurn(-45, 8000, 1, 1000, {0.02, 0, 0.08});
    // motionProfile.moveDistance(24, -45, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    // driveRightGroup.moveVoltage(4000);
    // driveLeftGroup.moveVoltage(7000);
    // pros::delay(850);
    // driveGroup.moveVoltage(0);

    // /*--Front push x2--*/
    // toggleLeftWing();
    // rotationTurn(90, 6000, 1, 1000, {0.02, 0, 0.08});
    // toggleRightWing();
    // driveGroup.moveVoltage(12000);
    // pros::delay(1200);
    // driveGroup.moveVoltage(0);
    // toggleLeftWing();
    // toggleRightWing();
    // motionProfile.moveDistance(-20, 90, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    // toggleLeftWing();
    // toggleRightWing();
    // driveGroup.moveVoltage(12000);
    // pros::delay(1200);
    // driveGroup.moveVoltage(0);
    // toggleLeftWing();
    // toggleRightWing();

    // /*--Get to side--*/
    // motionProfile.moveDistance(-10, 90, 1, {0.05, 0, 0.01}, {30, 0.01, 0.3, 3});
    // rotationTurn(0, 8000, 1, 1000, {0.02, 0, 0.08});
    // motionProfile.moveDistance(-35, 0, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    // rotationTurn(-45, 8000, 1, 1000, {0.02, 0, 0.08});
    // motionProfile.moveDistance(-16, -45, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    // driveLeftGroup.moveVoltage(-6000);
    // pros::delay(400);
    // rotationTurn(-135, 8000, 1, 1000, {0.02, 0, 0.08});
    // motionProfile.moveDistance(-9, -135, 1, {0.05, 0, 0.01}, {30, 0.01, 0.3, 3});

    // /*--Side push--*/
    // rotationTurn(-178, 8000, 1, 1000, {0.02, 0, 0.08});
    // driveGroup.moveVoltage(-12000);
    // pros::delay(1200);
    // driveGroup.moveVoltage(0);
    // motionProfile.moveDistance(10, -178, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    




    /*--old skills, gyro dead, cata positioning is dangerous or smth--*/

    /*--Deploy intake--*/
    catapult.moveVoltage(12000);
    pros::delay(225);
    catapult.moveVoltage(0);

    /*--Score alliance balls--*/

    motionProfile.moveDistance(-19.5, 0, 1, {0.05, 0, 0.01}, {20, 0.01, 0.3, 3});
    rotationTurn(23, 8000, 1, 1000, {0.02, 0, 0.08});
    driveGroup.moveVoltage(-10000);
    pros::delay(750);
    driveGroup.moveVoltage(0);
    motionProfile.moveDistance(15.2, 29, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});

    /*--Cata 44 balls--*/

    rotationTurn(100, 8000, 1, 1000, {0.02, 0, 0.08});
    pros::delay(500);
    catapult.moveVoltage(12000);
    pros::delay(42000);
    catapult.moveVoltage(0);
    // jank this shit has like a 50% of working LOL
    pros::delay(250);
    catapult.moveVoltage(12000);
    pros::delay(500);
    catapult.moveVoltage(0);

    /*--Push triballs in--*/
    // pros::delay(5000);
    motionProfile.moveDistance(-8, 100, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    rotationTurn(155, 8000, 1, 1000, {0.02, 0, 0.08});
    motionProfile.moveDistance(-21, 155, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    rotationTurn(119, 8000, 1, 1000, {0.02, 0, 0.08});
    motionProfile.moveDistance(-72, 119, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    rotationTurn(77, 8000, 1, 1000, {0.02, 0, 0.08});
    motionProfile.moveDistance(-20, 77, 1, {0.05, 0, 0.01}, {30, 0.01, 0.3, 3});
    // push from the front first, ill move this to the end later
    rotationTurn(28, 8000, 1, 1000, {0.02, 0, 0.08});
    driveGroup.moveVoltage(-12000);
    pros::delay(500);
    driveGroup.moveVoltage(0);
    motionProfile.moveDistance(15, 28, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    rotationTurn(150, 8000, 1, 1000, {0.02, 0, 0.08});
    motionProfile.moveDistance(36, 150, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    // pros::delay(5000);

    toggleRightWing();
    driveLeftGroup.moveVoltage(10500);
    driveRightGroup.moveVoltage(6000);
    pros::delay(750);
    toggleLeftWing();
    driveLeftGroup.moveVoltage(0);
    driveRightGroup.moveVoltage(0);
    // pros::delay(5000);
    rotationTurn(-63, 8000, 1, 1000, {0.02, 0, 0.08});
    motionProfile.moveDistance(32, -63, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3}, 2000);

    // pros::delay(5000);
    motionProfile.moveDistance(-25, -63, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3}), 2000;

    // pros::delay(5000);
    motionProfile.moveDistance(28, -63, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3}, 2000);
    toggleLeftWing();
    toggleRightWing();
    motionProfile.moveDistance(-16, -63, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3}, 2000);
}