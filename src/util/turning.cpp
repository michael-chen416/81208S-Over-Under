#include "main.h"

#define M_PI 3.14159265358979323846
#define CIRCUMFERENCE 4.0 * M_PI
#define ENCODER_TICKS 36000

/**
 * @brief rotationTurn
 * turns on the spot using both wheels
 * 
 * @param angle angle to be turned to
 * @param turnVoltage how fast the motors should spin, in millivolts
 * @param momentum tolerance 
 * @param timeout longest time the function can run for, in milliseconds
 * @param values pid values
 */
void rotationTurn(double angle, double turnVoltage, double momentum, uint32_t timeout, PIDvalues values){
    //setup variables
    uint32_t startTime = pros::millis();
    PID_controller turnController(values);
    turnController.SetTarget(angle);
    double startingAngle = getIMU();
    //have the loop include timeout and angle checking
    while(abs(angle - getIMU()) > momentum && timeout > pros::millis() - startTime){
        double outputValue = turnController.Calculate(getIMU());
        moveLeftGroup(turnVoltage * outputValue);
        moveRightGroup(turnVoltage * outputValue * (-1));
        pros::lcd::print(1, "Current angle: %f", getIMU());
        pros::delay(10);
    }
    moveLeftGroup(0);
    moveRightGroup(0);
}

/**
 * @brief pivotTurn
 * turns using 1 wheel
 * 
 * @param angle angle to be turned to
 * @param turnVoltage voltage to be spun at, in millivolts
 * @param momentum  tolerance
 * @param timeout maximum time the function can run for, in milliseconds
 * @param isLeft if we are using the left wheel or not
 * @param values pid values
 */
void pivotTurn(double angle, double turnVoltage, double momentum, uint32_t timeout, bool isLeft, PIDvalues values){
    PID_controller turnController(values);
    uint32_t startTime = pros::millis();
    turnController.SetTarget(angle);
    double startingAngle = getIMU();
    //angle checking
    while((abs(angle - getIMU()) > momentum) && (timeout > pros::millis() - startTime)){
        double outputValue = turnController.Calculate(getIMU());
        //only run 1 wheel based on configuration
        if(isLeft == true){
            moveLeftGroup(turnVoltage * outputValue);
        } else{
            moveRightGroup(turnVoltage * outputValue * (-1));
        }
        pros::lcd::print(1, "Current angle: %f", getIMU());
        pros::delay(10);
    }
    moveLeftGroup(0);
    moveRightGroup(0);
}

