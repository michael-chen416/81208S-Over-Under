#include "main.h"
bool counter = true;

void updatePneumatics(){
    if(leftButton.changedToPressed()){
        toggleLeftWing();
    }
    if(rightButton.changedToPressed()){
        toggleRightWing();
    }
}

/**
 * @brief opens the wing
 * 
 */
void openLeftWing() {
    leftWing.set_value(true);
    leftWingState = true;
}

/**
 * @brief opens the wing
 * 
 */
void openRightWing(){
    rightWing.set_value(true);
    rightWingState = true;
}

/**
 * @brief closes the wing
 * 
 */
void closeLeftWing() {
    leftWing.set_value(false);
    leftWingState = false;
}

/**
 * @brief closes the wing
 * 
 */
void closeRightWing(){
    rightWing.set_value(false);
    rightWingState = false;
}

/**
 * @brief toggles the wing
 * 
 */
void toggleLeftWing(){
    if(leftWingState == false) {
        openLeftWing();
    } else {
        closeLeftWing();
    }
}

/**
 * @brief toggles the wing
 * 
 */

void toggleRightWing(){
    if(rightWingState == false){
        openRightWing();
    } else {
        closeRightWing();
    }
}

/**
 * @brief extends the arm
 * 
 */
void extendArm() {
    hangMech.set_value(true);
    climbingState = true;
}

/**
 * @brief retracts the arm
 * 
 */
void retractArm() {
    hangMech.set_value(false);
    climbingState = false;
}

/**
 * @brief toggles arm state
 * 
 */
void extendMatchload(){
    matchloadBar.set_value(true);
    matchloadState = true;
}

void retractMatchload(){
    matchloadBar.set_value(false);
    matchloadState = false;
}