#include "main.h"

//controller
okapi::Controller controller(okapi::ControllerId::master);

//drive train
/*Left front*/okapi::Motor lf(8, true,okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);
/*Left bottom*/okapi::Motor lb(17, true, okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);
/*Left top*/okapi::Motor lt(18, false, okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);
/*Right front*/okapi::Motor rf(7, false, okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);
/*Right back*/okapi::Motor rb(20, false,okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);
/*Right top*/okapi::Motor rt(19, true, okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);

//drive group
okapi::MotorGroup driveLeftGroup = {lb, lf, lt};
okapi::MotorGroup driveRightGroup = {rb, rf, rt};
okapi::MotorGroup driveGroup = {lb, lf, lt, rb, rf, rt};
/*

lf 8
lb 17
lt 18

rf 7
rb 20
rt 19
*/


//Intake
/*Right intake*/ okapi::Motor ri(10, false, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees);
/*Left intake*/okapi::Motor li(9, true, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees);
/*Intake motor group*/ okapi::MotorGroup intake = {ri, li};

//Catapult
/*Catapult*/okapi::Motor catapult(11, false, okapi::AbstractMotor::gearset::red, okapi::AbstractMotor::encoderUnits::degrees);
/*Potentionmeter*/okapi::Potentiometer potentiometer('H');

//wings 
/*Left wing*/
/*Right wing*/
/*Back wing? [citation needed]*/