#include "main.h"

void skills()
{ // DO NOT DRY FIRE also gyro is acting up 
    motion_profile motionProfile;

    // normal setup
    // outtake while pushing front

    /*--Deploy intake + outtake alliance triball to offensive zone--*/
    catapult.moveVoltage(12000);
    intake.moveVoltage(12000);
    pros::delay(225);
    catapult.moveVoltage(0);
    pros::delay(200);
    intake.moveVoltage(0);

    /*--Catapult--*/
    motionProfile.moveDistance(20, 0, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    rotationTurn(-90, 8000, 1, 1000, {0.02, 0, 0.08});
    motionProfile.moveDistance(18, -90, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    rotationTurn(-105, 8000, 1, 1000, {0.02, 0, 0.08});
    motionProfile.moveDistance(4, -105, 1, {0.05, 0, 0.01}, {20, 0.01, 0.3, 3});
    catapult.moveVoltage(12000);
    pros::delay(42000);
    catapult.moveVoltage(0);

    /*--old skills, gyro dead, cata positioning is dangerous or smth--*/

    // /*--Deploy intake--*/
    // catapult.moveVoltage(12000);
    // pros::delay(225);
    // catapult.moveVoltage(0);

    // /*--Score alliance balls--*/

    // motionProfile.moveDistance(-19.5, 0, 1, {0.05, 0, 0.01}, {20, 0.01, 0.3, 3});
    // rotationTurn(23, 8000, 1, 1000, {0.02, 0, 0.08});
    // driveGroup.moveVoltage(-10000);
    // pros::delay(750);
    // driveGroup.moveVoltage(0);
    // motionProfile.moveDistance(15.2, 29, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});

    // /*--Cata 44 balls--*/

    // rotationTurn(100, 8000, 1, 1000, {0.02, 0, 0.08});
    // pros::delay(500);
    // catapult.moveVoltage(12000);
    // pros::delay(42000);
    // catapult.moveVoltage(0);
    // // jank this shit has like a 50% of working LOL
    // pros::delay(250);
    // catapult.moveVoltage(12000);
    // pros::delay(500);
    // catapult.moveVoltage(0);

    // /*--Push triballs in--*/
    // // pros::delay(5000);
    // motionProfile.moveDistance(-8, 100, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    // rotationTurn(155, 8000, 1, 1000, {0.02, 0, 0.08});
    // motionProfile.moveDistance(-21, 155, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    // rotationTurn(119, 8000, 1, 1000, {0.02, 0, 0.08});
    // motionProfile.moveDistance(-72, 119, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    // rotationTurn(77, 8000, 1, 1000, {0.02, 0, 0.08});
    // motionProfile.moveDistance(-20, 77, 1, {0.05, 0, 0.01}, {30, 0.01, 0.3, 3});
    // // push from the front first, ill move this to the end later
    // rotationTurn(28, 8000, 1, 1000, {0.02, 0, 0.08});
    // driveGroup.moveVoltage(-12000);
    // pros::delay(500);
    // driveGroup.moveVoltage(0);
    // motionProfile.moveDistance(15, 28, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    // rotationTurn(150, 8000, 1, 1000, {0.02, 0, 0.08});
    // motionProfile.moveDistance(36, 150, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    // // pros::delay(5000);

    // toggleRightWing();
    // driveLeftGroup.moveVoltage(10500);
    // driveRightGroup.moveVoltage(6000);
    // pros::delay(750);
    // toggleLeftWing();
    // driveLeftGroup.moveVoltage(0);
    // driveRightGroup.moveVoltage(0);
    // // pros::delay(5000);
    // rotationTurn(-63, 8000, 1, 1000, {0.02, 0, 0.08});
    // motionProfile.moveDistance(32, -63, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3}, 2000);

    // // pros::delay(5000);
    // motionProfile.moveDistance(-25, -63, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3}), 2000;

    // // pros::delay(5000);
    // motionProfile.moveDistance(28, -63, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3}, 2000);
    // toggleLeftWing();
    // toggleRightWing();
    // motionProfile.moveDistance(-16, -63, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3}, 2000);
}