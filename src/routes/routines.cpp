#include "main.h"
// movement profile = {0.05, 0, 0.01}
// rotation turn 8000, 0.5, 6000, {0.02, 0, 0.08} 90 deg

void scoring(){
    motion_profile motionProfile;

     /*--Deploy intake--*/
    catapult.moveVoltage(12000);
    pros::delay(150);
    catapult.moveVoltage(0);

    /*--Alliance triball--*/
    pros::delay(75);
    intake.moveVoltage(12000);
    pros::delay(250);
    intake.moveVoltage(0);
    motionProfile.moveDistance(3, 0, 1, {0.02, 0, 0.04}, {25, 0.01, 0.3, 25}); // to not hit bar
    pros::delay(100);
    rotationTurn(72, 8000, 1, 1200, {0.02, 0, 0.08}); // get to goal:
    pros::delay(100);
    motionProfile.moveDistance(18, 72, 1, {0.05, 0, 0.01}, {40, 0.1, 0.3, 3});
    pros::delay(100);
    rotationTurn(45, 8000, 1, 800, {0.02, 0, 0.08}); // pushing triball:
    intake.moveVoltage(-12000);
    pros::delay(650);
    motionProfile.moveDistance(13.5, 45, 1, {0.05, 0, 0.01}, {30, 0.01, 0.3, 30});
    intake.moveVoltage(0);
    // pros::delay(500);
    motionProfile.moveDistance(-14.5, 45, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});

    /*--Additional triballs--*/

    // pros::delay(500);
    rotationTurn(-22, 8000, 1, 1200, {0.02, 0, 0.08}); // get to first triball:
    // pros::delay(500);
    motionProfile.moveDistance(46, -22, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    intake.moveVoltage(12000);
    pros::delay(400);
    motionProfile.moveDistance(-1, 95, 1, {0.02, 0, 0.04}, {25, 0.01, 0.3, 25}); // get triball to goal:
    intake.moveVoltage(0);
    rotationTurn(95, 8000, 1, 1200, {0.02, 0, 0.08});
    motionProfile.moveDistance(8, 95, 1, {0.02, 0, 0.04}, {25, 0.01, 0.3, 25});
    intake.moveVoltage(-12000);
    pros::delay(500);
    intake.moveVoltage(0);
    motionProfile.moveDistance(-5, 95, 1, {0.02, 0, 0.04}, {25, 0.01, 0.3, 25});
    rotationTurn(20, 8000, 1, 1200, {0.02, 0, 0.08}); // get second and third triball:
    pros::delay(250);
    intake.moveVoltage(12000);
    motionProfile.moveDistance(24, 20, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    pros::delay(300);
    intake.moveVoltage(0);
    motionProfile.moveDistance(-7, 20, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    // pros::delay(500);
    rotationTurn(81.5, 8000, 1, 1200, {0.02, 0, 0.08});
    toggleLeftWing();                                  // open wings
    toggleRightWing();
    motionProfile.moveDistance(14.5, 81.5, 1, {0.05, 0, 0.01}, {45, 0.01, 0.3, 3});
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

void winpointAuton(){
    motion_profile motionProfile;

    /*--Deploy intake--*/
    catapult.moveVoltage(12000);
    pros::delay(200);
    catapult.moveVoltage(0);

    /*--Alliance triball--*/

    intake.moveVoltage(12000);
    pros::delay(175);
    intake.moveVoltage(0);
    motionProfile.moveDistance(-3, 0, 1, {0.02, 0, 0.04}, {25, 0.01, 0.3, 25});
    rotationTurn(90.5, 8000, 1, 1200, {0.02, 0, 0.08});
    motionProfile.moveDistance(17.75, 90.5, 1, {0.02, 0, 0.01}, {40, 0.01, 0.3, 3});
    pros::delay(250);//250
    rotationTurn(133, 8000, 1, 1200, {0.02, 0, 0.08});
    intake.moveVoltage(-12000);
    pros::delay(400);//500
    motionProfile.moveDistance(10.5, 133, 1, {0.05, 0, 0.01}, {30, 0.01, 0.3, 30}, 1000);
    motionProfile.moveDistance(-15.5, 133, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    intake.moveVoltage(0);

    /*--Remove Matchload triball--*/

    rotationTurn(75, 8000, 1, 1200, {0.02, 0, 0.08});
    motionProfile.moveDistance(-12.5, 75, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    rotationTurn(170, 8000, 1, 1200, {0.02, 0, 0.08});
    // extend matchload bar here!
    toggleMatchLoad();
    pros::delay(150);//200
    motionProfile.moveDistance(-9, 170, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3}, 1500);
    rotationTurn(75, 8000, 1, 1200, {0.02, 0, 0.08});
    pros::delay(150);
    toggleMatchLoad();
    motionProfile.moveDistance(-8, 75, 1, {0.05, 0, 0.01}, {40, 0.1, 0.3, 3});

    /*--Touch elevation bar--*/

    rotationTurn(-95, 8000, 1, 1500, {0.02, 0, 0.08}); // move towards wall to get to elevation bar
    motionProfile.moveDistance(4.5, -95, 1, {0.05, 0, 0.01}, {30, 0.1, 0.3, 30}); // risky, intake gets stuck
    rotationTurn(-135, 8000, 1, 1500, {0.02, 0, 0.08}); // face to elevation bar and touch with weird ziptie thing:
    intake.moveVoltage(-12000);
    motionProfile.moveDistance(26, -135, 1, {0.05, 0, 0.01}, {40, 0.1, 0.3, 3});
    intake.moveVoltage(0);
}

void skills(){ // DO NOT DRY FIRE also gyro is like acting up very inconsistant
    motion_profile motionProfile;
    
    /*--Deploy intake--*/
    catapult.moveVoltage(12000);
    pros::delay(200);
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
    //jank this shit has like a 50% of working LOL
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
    //SDE PuSHinG AHAHJDNLKSDSAHHDASSDjkADnjaDjk
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

void destruction(){
    motion_profile motionProfile;
    //soon
}