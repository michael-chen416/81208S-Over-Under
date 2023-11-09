#include "main.h"
// movement profile = {0.05, 0, 0.01}
// rotation turn 8000, 0.5, 6000, {0.02, 0, 0.08} 90 deg

void closeSide(){
    motion_profile motionProfile;

    /*--Alliance triball--*/

    motionProfile.moveDistance(3, 0, 1, {0.02, 0, 0.04}, {25, 0.01, 0.3, 25}); // to not hit bar
    pros::delay(250);
    rotationTurn(72, 8000, 1, 1200, {0.02, 0, 0.08}); // get to goal:
    pros::delay(250);
    motionProfile.moveDistance(18, 72, 1, {0.05, 0, 0.01}, {40, 0.1, 0.3, 3});
    pros::delay(500);
    rotationTurn(45, 8000, 1, 1200, {0.02, 0, 0.08}); // pushing triball:
    intake.moveVoltage(-12000);
    pros::delay(1000);
    motionProfile.moveDistance(13, 45, 1, {0.05, 0, 0.01}, {30, 0.01, 0.3, 30});
    intake.moveVoltage(0);
    // pros::delay(500);
    motionProfile.moveDistance(-14.5, 45, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});

    /*--Additional triballs--*/

    // pros::delay(500);
    rotationTurn(-22, 8000, 1, 1200, {0.02, 0, 0.08}); // get to first triball:
    // pros::delay(500);
    motionProfile.moveDistance(46, -22, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    intake.moveVoltage(12000);
    pros::delay(500);
    motionProfile.moveDistance(-1, 90, 1, {0.02, 0, 0.04}, {25, 0.01, 0.3, 25}); // get triball to goal:
    intake.moveVoltage(0);
    rotationTurn(90, 8000, 1, 1200, {0.02, 0, 0.08});
    motionProfile.moveDistance(3, 90, 1, {0.02, 0, 0.04}, {25, 0.01, 0.3, 25});
    intake.moveVoltage(-12000);
    pros::delay(500);
    intake.moveVoltage(0);
    rotationTurn(20, 8000, 1, 1200, {0.02, 0, 0.08}); // get second and third triball:
    pros::delay(250);
    intake.moveVoltage(12000);
    motionProfile.moveDistance(24, 20, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    pros::delay(250);
    intake.moveVoltage(0);
    // pros::delay(500);
    rotationTurn(135, 8000, 1, 1200, {0.02, 0, 0.08}); // pushing triballs:
    toggleLeftWing();                                  // open wings
    toggleRightWing();
    // pros::delay(500);
    intake.moveVoltage(-12000);
    motionProfile.moveDistance(30, 135, 1, {0.05, 0, 0.01}, {45, 0.01, 0.3, 3});
    // pros::delay(500);
    intake.moveVoltage(0);
    motionProfile.moveDistance(-16, 135, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    toggleLeftWing();
    toggleRightWing();
}

void farSideShort(){
    motion_profile motionProfile;

    /*--Alliance triball--*/

    motionProfile.moveDistance(-3, 0, 1, {0.02, 0, 0.04}, {25, 0.01, 0.3, 25}); // to not hit bar
    rotationTurn(90.5, 8000, 1, 1200, {0.02, 0, 0.08});                         // get to goal:
    motionProfile.moveDistance(17.75, 90.5, 1, {0.02, 0, 0.01}, {40, 0.01, 0.3, 3});
    pros::delay(250);
    rotationTurn(133, 8000, 1, 1200, {0.02, 0, 0.08});
    intake.moveVoltage(-12000);
    pros::delay(500);
    motionProfile.moveDistance(10.5, 133, 1, {0.05, 0, 0.01}, {30, 0.01, 0.3, 30}); // pushing triball: // no greater than 9 no less than 8.5
    motionProfile.moveDistance(-15.5, 133, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});

    /*--Matchload ball--*/

    toggleMatchLoad();
    intake.moveVoltage(0);
    // extend matchload bar here!
    pros::delay(5000);
    rotationTurn(180, 8000, 1, 1000, {0.02, 0, 0.08}); // get matchload out of corner:
    driveLeftGroup.moveVoltage(8000);
    driveRightGroup.moveVoltage(-8000);
    pros::delay(200);
    driveLeftGroup.moveVoltage(0);
    driveRightGroup.moveVoltage(0);
    pros::delay(250);

    /*--Touch elevation bar--*/

    rotationTurn(-95, 8000, 1, 1500, {0.02, 0, 0.08}); // move towards wall to get to elevation bar
    toggleMatchLoad();
    motionProfile.moveDistance(15.5, -95, 1, {0.05, 0, 0.01}, {40, 0.1, 0.3, 3});
    rotationTurn(-135, 8000, 1, 1500, {0.02, 0, 0.08}); // face to elevation bar and touch with weird ziptie thing:
    intake.moveVoltage(-12000);
    motionProfile.moveDistance(34, -135, 1, {0.05, 0, 0.01}, {40, 0.1, 0.3, 3});
    // pros::delay(2000);
}

void farSideLong(){
    motion_profile motionProfile;
    
    /*--Alliance triball--*/

    motionProfile.moveDistance(-3, 0, 1, {0.02, 0, 0.04}, {25, 0.01, 0.3, 25}); // to not hit bar
    rotationTurn(90.5, 8000, 1, 1200, {0.02, 0, 0.08});                         // get to goal:
    motionProfile.moveDistance(17.75, 90.5, 1, {0.02, 0, 0.01}, {40, 0.01, 0.3, 3});
    pros::delay(250);
    rotationTurn(133, 8000, 1, 1200, {0.02, 0, 0.08});
    intake.moveVoltage(-12000);
    pros::delay(500);
    motionProfile.moveDistance(10.5, 133, 1, {0.05, 0, 0.01}, {30, 0.01, 0.3, 30}); // pushing triball: // no greater than 9 no less than 8.5
    motionProfile.moveDistance(-15.5, 133, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});

    /*--Matchload ball--*/

    intake.moveVoltage(0);
    toggleMatchLoad(); // extend matchload bar here!
    pros::delay(5000);
    rotationTurn(180, 8000, 1, 1000, {0.02, 0, 0.08}); // get matchload out of corner:
    driveLeftGroup.moveVoltage(8000);
    driveRightGroup.moveVoltage(-8000);
    pros::delay(200);
    driveLeftGroup.moveVoltage(0);
    driveRightGroup.moveVoltage(0);
    pros::delay(250);
    // motionProfile.moveDistance(5, -150, 1, {0.05, 0, 0.01}, {30, 0.01, 0.3, 30});
    // pros::delay(3000);

    /*--Get matchload ball--*/
    
    toggleMatchLoad();
    motionProfile.moveDistance(8, -144, 1, {0.05, 0, 0.01}, {30, 0.01, 0.3, 30});
    rotationTurn(47, 8000, 1, 1000, {0.02, 0, 0.08});
    intake.moveVoltage(12000);
    motionProfile.moveDistance(15.5, 47, 1, {0.05, 0, 0.01}, {30, 0.01, 0.3, 30});
    pros::delay(750);
    intake.moveVoltage(0);
    motionProfile.moveDistance(-8, 47, 1, {0.05, 0, 0.01}, {30, 0.01, 0.3, 30});

    /*--Get to elevation bar--*/

    rotationTurn(-95, 8000, 1, 1500, {0.02, 0, 0.08});
    motionProfile.moveDistance(15, -95, 1, {0.05, 0, 0.01}, {40, 0.1, 0.3, 3});
    rotationTurn(-135, 8000, 1, 1500, {0.02, 0, 0.08});
    intake.moveVoltage(-12000);
    motionProfile.moveDistance(22.5, -135, 1, {0.05, 0, 0.01}, {40, 0.1, 0.3, 3});
    
}

void skills(){
    motion_profile motionProfile;

    /*--Score alliance balls--*/

    motionProfile.moveDistance(-19.5, 0, 1, {0.05, 0, 0.01}, {20, 0.01, 0.3, 3});
    rotationTurn(23, 8000, 1, 1000, {0.02, 0, 0.08});
    driveGroup.moveVoltage(-10000);
    pros::delay(750);
    driveGroup.moveVoltage(0);
    motionProfile.moveDistance(15, 29, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});

    /*--Cata 44 balls--*/
    
    rotationTurn(95, 8000, 1, 1000, {0.02, 0, 0.08});
    // catapult.moveVoltage(12000);
    // pros::delay(44000);
    // catapult.moveVoltage(0);    

    /*--Push triballs in--*/

    pros::delay(5000);
    motionProfile.moveDistance(-8, 95, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});    
    rotationTurn(155, 8000, 1, 1000, {0.02, 0, 0.08});
    motionProfile.moveDistance(-21, 155, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    rotationTurn(119, 8000, 1, 1000, {0.02, 0, 0.08});
    motionProfile.moveDistance(-72, 119, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    rotationTurn(77, 8000, 1, 1000, {0.02, 0, 0.08});
    motionProfile.moveDistance(-20, 77, 1, {0.05, 0, 0.01}, {30, 0.01, 0.3, 3});
    rotationTurn(28, 8000, 1, 1000, {0.02, 0, 0.08});
    
    rotationTurn(150, 8000, 1, 1000, {0.02, 0, 0.08});
    motionProfile.moveDistance(36, 150, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    toggleLeftWing();
    toggleRightWing();
    pros::delay(5000);
    driveLeftGroup.moveVoltage(10500);
    driveRightGroup.moveVoltage(6000);
    pros::delay(800);
    driveLeftGroup.moveVoltage(0);
    driveRightGroup.moveVoltage(0);
    pros::delay(5000);
    rotationTurn(-63, 8000, 1, 1000, {0.02, 0, 0.08});
    motionProfile.moveDistance(29, -63, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3}); //w at?
    toggleLeftWing();
    toggleRightWing();
    pros::delay(5000);
    motionProfile.moveDistance(-32, -63, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3}); //w at?
    toggleLeftWing();
    toggleRightWing();
    pros::delay(5000);
    motionProfile.moveDistance(34, -63, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3}); //w at?
    pros::delay(750);
    motionProfile.moveDistance(-16, -63, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
}
    // This goes on line 181.
    // driveGroup.moveVoltage(-12000);
    // pros::delay(750);
    // driveGroup.moveVoltage(0);
    // motionProfile.moveDistance(15, 28, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    // driveGroup.moveVoltage(-12000);
    // pros::delay(1000);
    // driveGroup.moveVoltage(0);
    // motionProfile.moveDistance(12, 28, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});