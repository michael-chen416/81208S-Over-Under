#include "subsystems/catapult.hpp"

//uint32_t lastPressed = -1500;  // needs to be adjusted.
// catapult down positon: 1600 ish
// catapult up position: 8

/* ++++++++++++++ NOTICE ++++++++++++++*/
/* Catapult slipgear works now yippee, but the code doesn't for some reason sob */
void OpCatapult() {
  pros::lcd::print(5, "potentiometer value: %f", potentiometer.get());
  //okapi::ControllerButton fire(okapi::ControllerDigital::R1);





}