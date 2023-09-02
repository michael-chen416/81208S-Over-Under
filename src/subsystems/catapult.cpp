#include "subsystems/catapult.hpp"
 
//

uint32_t lastPressed = 1500;
//catapult down positon 1480 up position is like 8
void resetCatapult(){
    okapi::ControllerButton fire(okapi::ControllerDigital::R1);
    if(fire.changedToPressed()){
        lastPressed = pros::millis; //fuck! why won't it convert without errors
    }
    if(pros::millis() - lastPressed < 350){
        if(potentiometer.get() > 1470) {
            catapult.moveVoltage(12000);
        } else {
            catapult.moveVoltage(0);
        }
    } else { //after reset, always move down to primed position
        if( potentiometer.get() < 1470) { // this should move the catapult to a position of like 
        catapult.moveVoltage(12000);
        } else {
            catapult.moveVoltage(0);
        }
    }
}

void fireCatapult(){ // improve
    okapi::ControllerButton fire(okapi::ControllerDigital::R1);
    if(potentiometer.get() < 1480 && fire.changedToPressed()){ // if the catapult is in a down positon, probably primed.
        catapult.moveVoltage(12000);
    } 
    
}