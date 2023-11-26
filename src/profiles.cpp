#include "main.h"

bool leftWingState = false;
bool rightWingState = false;
bool matchloadState = false;
bool climbingState = false;
bool cataToggle = false;
double angleOffset = 0;

// Controller
okapi::Controller controller(okapi::ControllerId::master);

okapi::ControllerAnalog leftY(okapi::ControllerAnalog::leftY);
okapi::ControllerAnalog rightX(okapi::ControllerAnalog::rightX);
okapi::ControllerAnalog rightY(okapi::ControllerAnalog::rightY);
okapi::ControllerButton l1(okapi::ControllerDigital::L1);
okapi::ControllerButton l2(okapi::ControllerDigital::L2);
okapi::ControllerButton r1(okapi::ControllerDigital::R1);
okapi::ControllerButton r2(okapi::ControllerDigital::R2);
okapi::ControllerButton rightButton(okapi::ControllerDigital::right);
okapi::ControllerButton downButton(okapi::ControllerDigital::down);
okapi::ControllerButton leftButton(okapi::ControllerDigital::left);
okapi::ControllerButton upButton(okapi::ControllerDigital::up); // no current bind atm
okapi::ControllerButton AButton(okapi::ControllerDigital::A);
okapi::ControllerButton BButton(okapi::ControllerDigital::B);
okapi::ControllerButton XButton(okapi::ControllerDigital::X);
okapi::ControllerButton YButton(okapi::ControllerDigital::Y);

// Drivetrain
/* Left front */ okapi::Motor lf(8, true, okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);
/* Left bottom */ okapi::Motor lb(17, true, okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);
/* Left top */ okapi::Motor lt(18, false, okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);
/* Right front */ okapi::Motor rf(7, false, okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);
/* Right back */ okapi::Motor rb(20, false, okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);
/* Right top */ okapi::Motor rt(19, true, okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);

// Drivetrain Motor Group
/* Left group*/ okapi::MotorGroup driveLeftGroup = {lb, lf, lt};
/* Right group*/ okapi::MotorGroup driveRightGroup = {rb, rf, rt};
okapi::MotorGroup driveGroup = {lb, lf, lt, rf, rb, rt};

// Intake
/* Right intake */ okapi::Motor ri(10, true, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees);
/* Left intake */ okapi::Motor li(9, false, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees);
/* Intake motor group */ okapi::MotorGroup intake = {ri, li};

// Catapult
/* Catapult */ okapi::Motor catapult(13, true, okapi::AbstractMotor::gearset::red, okapi::AbstractMotor::encoderUnits::degrees);
/* Potentionmeter */ okapi::Potentiometer potentiometer('H');

// Auton
/* Gyro */ pros::Imu gyro(15);

// Pneumatics
pros::ADIDigitalOut rightWing('A', LOW); // change these values later
pros::ADIDigitalOut leftWing('D', LOW);
pros::ADIDigitalOut matchloadBar('E', LOW);