#include "okapi/api.hpp"
// Controller
extern okapi::Controller controller;

// Drivetrain 
/* Left front */extern okapi::Motor lf;
/* Left bottom */extern okapi::Motor lb;
/* Left top */extern okapi::Motor lt;
/* Right front */extern okapi::Motor rf;
/* Right back */extern okapi::Motor rb;
/* Right top */extern okapi::Motor rt;

// Drive motorgroups
/* Left group */extern okapi::MotorGroup driveLeftGroup;
/* Right group */extern okapi::MotorGroup driveRightGroup;

// Intake 
/* Right intake */extern okapi::Motor ri;
/* Left intake */extern okapi::Motor li;
/* Intake motor group */extern okapi::MotorGroup intake;

// Catapult
/* Catapult */extern okapi::Motor catapult;
/* Catapult potentiometer */extern okapi::Potentiometer potentiometer;
