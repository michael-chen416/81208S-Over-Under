#include "main.h"
#include "util/PID_controller.hpp"

using namespace std;

/**
 * @brief Construct a new pid controller::pid controller object
 *
 */
PID_controller::PID_controller()
{
    _error = _lastError = _sumOfError = _maxSumOfError = _sumErrorRange = 0;
    _outputRange = 1.0;
    _target = 0;
    _outputValue = 0;
}

/**
 * @brief Destroy the pid controller::pid controller object
 *
 *
 */
PID_controller::~PID_controller()
{
}

/**
 * @brief Construct a new pid controller::pid controller object
 * full init of a PID_controller object
 * all other values are basically preset so theyre auto derfined
 * @param values pid values
 */
PID_controller::PID_controller(PIDvalues values)
{ // write kp ki kd using this
    _values = values;
    _error = _lastError = _sumOfError = _maxSumOfError = _sumErrorRange = 0;
    _outputRange = 1.0;
    _target = 0;
    _outputValue = 0;
}

/**
 * @brief sets pid values
 *
 * @param values values
 */
void PID_controller::Set_Parameters(PIDvalues values)
{ // usually odnt need to use this
    _values = values;
}

/**
 * @brief sets the target for the independent variable
 *
 * @param target target value
 */
void PID_controller::SetTarget(double target)
{ // mandatory to set target before running calculate, target heading is almost never 0
    _target = target;
}

/**
 * @brief sets maxSumError for Ki
 *
 * @param maxSumError
 */
void PID_controller::SetMaxSumOfError(double maxSumError)
{ // usualyl we dont use ki, so normally dont need
    _maxSumOfError = abs(maxSumError);
}

double PID_controller::GetError()
{ // testing
    return _error;
}

/**
 * @brief calculates an output value based on currentreading and previously set values
 *
 * @param currentReading current reading of independent variable
 * @return double output value from -1 to 1
 */
double PID_controller::Calculate(double currentReading)
{
    _error = _target - currentReading;

    // process with Ki first
    if (abs(_error) < _sumErrorRange)
    {
        _sumOfError += _error * _values.ki;
    }

    // if we cross over our target value, have to reset ki so we dont momentum over
    if (sgn(_error) != sgn(_lastError))
    {
        _sumOfError = 0;
    }

    // make sure integral doesnt cross over the threshold

    _sumOfError = abs(_sumOfError) > _maxSumOfError ? sgn(_sumOfError) * _maxSumOfError : _sumOfError;

    // proportional and derivative parts
    _outputValue = _values.kp * _error + _values.kd * (_error - _lastError) + _sumOfError;
    _outputValue = clamp(_outputValue, -_outputRange, _outputRange);
    _lastError = _error;

    return _outputValue;
}
