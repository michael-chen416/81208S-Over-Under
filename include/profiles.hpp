#include "okapi/api.hpp"
//Master Controller
extern okapi::Controller controller;

//Drivetrain motors
/*Left front*/extern okapi::Motor lf;
/*Left bottom*/extern okapi::Motor lb;
/*Left top*/extern okapi::Motor lt;
/*Right front*/extern okapi::Motor rf;
/*Right back*/extern okapi::Motor rb;
/*Right top*/extern okapi::Motor rt;

//Drive motor groups
extern okapi::MotorGroup driveLeftGroup;
extern okapi::MotorGroup driveRightGroup;
extern okapi::MotorGroup driveGroup;


//Intake motors
/*Right intake*/extern okapi::Motor ri;
/*Left intake*/extern okapi::Motor li;
/*Intake motor group*/extern okapi::MotorGroup intake;
/*Catapult*/extern okapi::Motor catapult;


//sensors
/*Catapult potentiometer*/extern okapi::Potentiometer potentiometer;

//Pistons
/*Left Wing*/
/*Right Wing*/
/*Back wing thing*/