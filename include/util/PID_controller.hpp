#ifndef PID_CONTROLLER
#define PID_CONTROLLER

struct PIDvalues {
    double kp;
    double ki;
    double kd;
};

class PID_controller {
private:
    PIDvalues _values;
    double _target; 
    double _error;
    double _lastError;
    double _sumOfError;
    double _maxSumOfError;
    double _sumErrorRange;
    double _outputRange;
    double _outputValue;

public:
    PID_controller();

    ~PID_controller();

    PID_controller(PIDvalues values);

    void Set_Parameters(PIDvalues values);

    void SetTarget(double target);

    void SetMaxSumOfError(double maxSumOfError);

    double GetError();

    double Calculate(double currentReading);

    void turnToAngle(double angle, double turnVoltage, PIDvalues values);

    template <class T> inline int sgn(T v) {
        return (v > T(0)) - (v < T(0));
    }
};

#endif