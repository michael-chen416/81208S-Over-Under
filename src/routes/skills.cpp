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
    pros::delay(125);
    catapult.moveVoltage(0);

    /*--Score alliance balls--*/

    motionProfile.moveDistance(-19.5, 0, 1, {0.05, 0, 0.01}, {20, 0.01, 0.3, 3});
    rotationTurn(23, 8000, 1, 1000, {0.02, 0, 0.08});
    driveGroup.moveVoltage(-10000);
    pros::delay(725);
    driveGroup.moveVoltage(0);
    motionProfile.moveDistance(15.2, 29, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});

    /*--Cata 44 balls--*/

    rotationTurn(100, 8000, 1, 1000, {0.02, 0, 0.08});
    pros::delay(500);
    catapult.moveVoltage(12000);
    pros::delay(42000);
    catapult.moveVoltage(0);
    // jank this shit has like a 50% of working LOL
    gyro.reset(false);
    pros::delay(250);
    catapult.moveVoltage(12000);
    pros::delay(500);
    catapult.moveVoltage(0);
    pros::delay(1600);
    
    /*--Push triballs in--*/
    // pros::delay(5000);
    motionProfile.moveDistance(-8, 100 - 100, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    rotationTurn(155 - 100, 8000, 1, 1000, {0.02, 0, 0.08});
    motionProfile.moveDistance(-21, 155 - 100, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    rotationTurn(119 - 100, 8000, 1, 1000, {0.02, 0, 0.08});
    motionProfile.moveDistance(-72, 119 - 100, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    rotationTurn(77 - 100, 8000, 1, 1000, {0.02, 0, 0.08});
    motionProfile.moveDistance(-20, 77 - 100, 1, {0.05, 0, 0.01}, {30, 0.01, 0.3, 3});
    // push from the front first, ill move this to the end later
    rotationTurn(28 - 100, 8000, 1, 1000, {0.02, 0, 0.08});
    driveGroup.moveVoltage(-12000);
    pros::delay(500);
    driveGroup.moveVoltage(0);
    motionProfile.moveDistance(15, 28 - 100, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    rotationTurn(150 - 100, 8000, 1, 1000, {0.02, 0, 0.08});
    motionProfile.moveDistance(36, 150 - 100, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    // pros::delay(5000);

    toggleRightWing();
    driveLeftGroup.moveVoltage(10500);
    driveRightGroup.moveVoltage(6000);
    pros::delay(750);
    toggleLeftWing();
    driveLeftGroup.moveVoltage(0);
    driveRightGroup.moveVoltage(0);
    // pros::delay(5000);
    rotationTurn(-63 - 100, 8000, 1, 1000, {0.02, 0, 0.08});
    motionProfile.moveDistance(32, -63 - 100, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3}, 2000);

    // pros::delay(5000);
    motionProfile.moveDistance(-25, -63 - 100, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3}), 2000;

    // pros::delay(5000);
    motionProfile.moveDistance(28, -63 - 100, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3}, 2000);
    toggleLeftWing();
    toggleRightWing();
    motionProfile.moveDistance(-16, -63 - 100, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3}, 2000);
}

void skills2() {
    motion_profile motionProfile;

    // normal setup
    // outtake while pushing front

    /*--Deploy intake--*/
    catapult.moveVoltage(12000);
    pros::delay(125);
    catapult.moveVoltage(0);
    
    // /*--Alliance Balls--*/
    // motionProfile.moveDistance(-21, 0, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    // rotationTurn(45, 6000, 1, 1000, {0.02, 0, 0.08});
    // driveGroup.moveVoltage(-12000);
    // pros::delay(600);
    // driveGroup.moveVoltage(0);
    // motionProfile.moveDistance(8, 45, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});

    // /*--Cata--*/
    // rotationTurn(135, 8000, 1, 1000, {0.02, 0, 0.08});
    // motionProfile.moveDistance(-12, 135, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    // rotationTurn(103, 8000, 1, 1000, {0.02, 0, 0.08});
    // motionProfile.moveDistance(17, 103, 1, {0.05, 0, 0.01}, {30, 0.01, 0.3, 3}, 750);

    /*--Setup--*/
    motionProfile.moveDistance(12.5, 0, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 40});
    rotationTurn(-74.5, 8000, 1, 1000, {0.02, 0, 0.08});//77
    motionProfile.moveDistance(12, -74.5, 1, {0.05, 0, 0.01}, {30, 0.01, 0.3, 30});

    /*--Firing--*/
    pros::delay(200);
    catapult.moveVoltage(12000);
    pros::delay(42500);//We should create an auto setting function, do this later
    catapult.moveVoltage(0);
    gyro.reset();
    pros::delay(2500);

    /*--Get alliance triball and get to other side--*/
    motionProfile.moveDistance(-7.5, 103-110.5-1, 1, {0.05, 0, 0.01}, {20, 0.01, 0.3, 3});
    rotationTurn(-45+225-110.5-1, 8000, 1, 1000, {0.02, 0, 0.08});
    motionProfile.moveDistance(-24, -45+225-110.5-1, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    rotationTurn(-90+225-110.5-1, 8000, 1, 1000, {0.02, 0, 0.08});
    motionProfile.moveDistance(-77, -90+225-110.5-1, 1, {0.05, 0, 0.01}, {40, 0.1, 0.3, 3});

    /*--Get to center--*/
    rotationTurn(-135+225-110.5-2.5, 8000, 1, 1000, {0.02, 0, 0.08});
    motionProfile.moveDistance(-12, -135+225-110.5-2.5, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    rotationTurn(-45+225-110.5-2.5, 8000, 1, 1000, {0.02, 0, 0.08});
    motionProfile.moveDistance(23, -45+225-110.5-2.5, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    //ok move forward a lil bit ill ad this part later on peter
    driveRightGroup.moveVoltage(4500);
    driveLeftGroup.moveVoltage(7000);
    pros::delay(950);//850
    driveGroup.moveVoltage(0);

    /*--Front push x2--*/
    toggleLeftWing();
    moveLeftGroup(12000);
    moveRightGroup(-12000);
    pros::delay(250);
    driveGroup.moveVoltage(0);
    rotationTurn(-179+3.5/*-179*/, 6000, 1, 1000, {0.02, 0, 0.08});
    toggleRightWing();
    driveGroup.moveVoltage(12000);
    pros::delay(1200);
    driveGroup.moveVoltage(0);
    toggleLeftWing();
    toggleRightWing();
    motionProfile.moveDistance(-20, 90-135-110.5-2.5, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});//eh we can work on this shit later
    toggleLeftWing();
    toggleRightWing();
    driveGroup.moveVoltage(12000);
    pros::delay(1200);
    driveGroup.moveVoltage(0);
    toggleLeftWing();
    toggleRightWing();

    // /*--Get to side--*/
    // motionProfile.moveDistance(-22, 90-135-103, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    // rotationTurn(-122, 8000, 1, 1000, {0.02, 0, 0.08});
    // motionProfile.moveDistance(-122, 90-135-103, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    

    // /*--Side push--*/
    // rotationTurn(-180+225-103, 8000, 1, 1000, {0.02, 0, 0.08});
    // driveGroup.moveVoltage(-12000);
    // pros::delay(1200);
    // driveGroup.moveVoltage(0);
    // motionProfile.moveDistance(10, -180+225-103, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
}