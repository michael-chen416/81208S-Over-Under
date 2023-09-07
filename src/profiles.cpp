#include "main.h"

// Controller
okapi::Controller controller(okapi::ControllerId::master);

// Drivetrain
/* Left front */okapi::Motor lf(8, true,okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);
/* Left bottom */okapi::Motor lb(17, true, okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);
/* Left top */okapi::Motor lt(18, false, okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);
/* Right front */okapi::Motor rf(7, false, okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);
/* Right back */okapi::Motor rb(20, false,okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);
/* Right top */okapi::Motor rt(19, true, okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);

// Drivetrain Motor Group
/* Left group*/okapi::MotorGroup driveLeftGroup = {lb, lf, lt};
/* Right group*/okapi::MotorGroup driveRightGroup = {rb, rf, rt};

// Intake
/* Right intake */ okapi::Motor ri(10, true, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees);
/* Left intake */okapi::Motor li(9, false, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees);
/* Intake motor group */ okapi::MotorGroup intake = {ri, li};

// Catapult
/* Catapult */okapi::Motor catapult(11, true, okapi::AbstractMotor::gearset::red, okapi::AbstractMotor::encoderUnits::degrees);
/* Potentionmeter */okapi::Potentiometer potentiometer('H');
