#include "subsystems/catapult.hpp"

uint32_t lastPressed = 1500; // needs to be adjusted.
//catapult down positon: 1480 
//catapult up position: 8
void OpCatapult(){
    okapi::ControllerButton fire(okapi::ControllerDigital::R1);
    if(potentiometer.get()>1470){   //if not shooting, move the catapult into the correct possition.
        catapult.moveVoltage(12000); 
    } else if(fire.changedToPressed()){
        lastPressed = pros::millis();
        catapult.moveVoltage(12000);
        //pros::delay(); find out time required.
    } else if(fire.isPressed() && pros::millis - lastPressed > 350){ // fix error
        catapult.moveVoltage(12000);
    } else{
        catapult.moveVoltage(0);
    }
}

void fireCatapult(){ //unused
    okapi::ControllerButton fire(okapi::ControllerDigital::R1);
    if(potentiometer.get() < 1480 && fire.changedToPressed()){ 
        catapult.moveVoltage(12000);
    } 
    
}