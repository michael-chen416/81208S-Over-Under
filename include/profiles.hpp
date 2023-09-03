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
/*Left group*/extern okapi::MotorGroup driveLeftGroup;
/*Right group*/extern okapi::MotorGroup driveRightGroup;


//Intake motors
/*Right intake*/extern okapi::Motor ri;
/*Left intake*/extern okapi::Motor li;
/*Intake motor group*/extern okapi::MotorGroup intake;


/*Catapult*/extern okapi::Motor catapult;


//sensors
/*Catapult potentiometer*/extern okapi::Potentiometer potentiometer;
