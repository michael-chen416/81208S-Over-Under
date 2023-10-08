#include "main.h"


    // motionProfile.moveDistance(12, 0, 2, {0.04, 0, 0.07}, {40, 0.1, 0.4, 10});



void winPointAuton(){
    
    motion_profile motionProfile;
    
    // extendPTO();

    // while(potentiometer.get() >= 800){
    //     rPTO.moveVoltage(-12000);
    //     lPTO.moveVoltage(-12000);
    // }
    // rPTO.moveVoltage(0);
    // lPTO.moveVoltage(0);

    progIntake();

    motionProfile.moveDistance(22, 0, 2, {0.03, 0, 0.08}, {30, 0.1, 0.3, 10});

    pivotTurn(48, 8000, 0.5, 600, true, {0.019, 0, 0.04});
    pros::delay(10);

    motionProfile.moveDistance(-3, 48, 2,{0.03, 0, 0.08}, {10, 0.001, 0.003, 10});
    intake.moveVoltage(-12000);
    motionProfile.moveDistance(10, 48, 2,{0.03, 0, 0.08}, {60, 0.001, 0.003, 60}, 500);
    // motionProfile.moveDistance(-10, 48, 2,{0.03, 0, 0.08}, {10, 0.001, 0.003, 10});
    
    intake.moveVoltage(0);

    motionProfile.moveDistance(-5, 48, 2,{0.03, 0, 0.08}, {10, 0.001, 0.003, 10});

    rotationTurn(0, 8000, 0.5,600,{0.019, 0, 0.04});
    pros::delay(10);
    motionProfile.moveDistance(-20, 0, 2,{0.03, 0, 0.08}, {30, 0.001, 0.003, 30});
    //
    rotationTurn(-45, 8000, 0.5,600,{0.019, 0, 0.04});
    motionProfile.moveDistance(-40, -45, 2,{0.03, 0, 0.08}, {30, 0.001, 0.003, 30});

}

void closeSide(){
    motion_profile motionProfile;
   
    progIntake();

    motionProfile.moveDistance(19, 0, 2, {0.03, 0, 0.08}, {30, 0.1, 0.3, 10});

    pivotTurn(-48, 8000, 0.5, 600, false, {0.019, 0, 0.04});
    pros::delay(10);

    motionProfile.moveDistance(5, -48, 2,{0.03, 0, 0.08}, {10, 0.001, 0.003, 10}, 50);
    intake.moveVoltage(-12000);

    motionProfile.moveDistance(12, -48, 2,{0.03, 0, 0.08}, {60, 0.001, 0.003, 60}, 500);
    motionProfile.moveDistance(-15, -48, 2,{0.03, 0, 0.08}, {10, 0.001, 0.003, 10},500);
    
    intake.moveVoltage(0);


    rotationTurn(-116, 6000, 0.5,600,{0.019, 0, 0.04});
    intake.moveVoltage(12000);
    motionProfile.moveDistance(48, -116, 2, {0.03, 0, 0.08}, {40, 0.1, 0.4, 3});

    rotationTurn(30, 6000, 0.5,850,{0.019, 0, 0.04});
    intake.moveVoltage(-12000);
    pros::delay(500);
    intake.moveVoltage(12000);
    rotationTurn(-65, 6000, 0.5,850,{0.019, 0, 0.04});
    motionProfile.moveDistance(19,-70, 2,{0.03, 0, 0.08}, {40, 0.1, 0.4, 3});
    rotationTurn(45, 6000, 0.5,850,{0.019, 0, 0.04});
    intake.moveVoltage(-12000);






    // rotationTurn(-90, 6000, 0.5, 600, {0.019, 0, 0.04});
    // intake.moveVoltage(12000);
    // pros::delay(25);
    // intake.moveVoltage(0);
    // pivotTurn(-90, 6000, 0.5, 600, true, {0.019, 0, 0.04});
    

    // motionProfile.moveDistance(24, 0, {0.03, 0, 0.08}, {40, 0.1, 0.4, 10});
    // pros::delay(200);

    // intake.moveVoltage(0);
    
    // // pivotTurn(180, 6000, 0.5, 600, true, {0.019, 0, 0.04});
    // rotationTurn(180, 6000, 0.5, 600, {0.019, 0, 0.04});

    // motionProfile.moveDistance(36, 0, {0.03, 0, 0.08}, {40, 0.1, 0.4, 10});

    // intake.moveVoltage(-12000);

    // pros::delay(200);
    // intake.moveVoltage(0);

}

// void startIntake(){
//         intake.moveVoltage(12000);
// }

// void stopIntake(){
//     intake.moveVoltage(0);
// }
// void reverseIntake(){
//     intake.moveVoltage(-12000);
// }

//void rotationTurn(double angle, double turnVoltage, double momentum, uint32_t timeout, PIDvalues values){
//void pivotTurn(double angle, double turnVoltage, double momentum, uint32_t timeout, bool isLeft, PIDvalues values){
//void travelTurn(double distance, double driveVoltage, double angle, double turnVoltage, double momentum, uint32_t timeout, PIDvalues values){

