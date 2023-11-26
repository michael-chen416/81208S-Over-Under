#ifndef MOTION_PROFILE
#define MOTION_PROFILE

#include <vector>
#include "okapi/api.hpp"
#include "util/PID_controller.hpp"

struct MotionData
{
    double maxVelocity; // as a percentage of max speed, as inches traveled per second
    double accelTime;   // time to accel from 0 to max
    double decelTime;   // time to decel from max to 0
    double minVelocity; // as a percentage of minimum speed
};

class motion_profile
{
private:
    MotionData _data;

public:
    motion_profile();

    ~motion_profile();

    void moveDistance(double distance, double direction, double offset, PIDvalues values, MotionData data);

    void moveDistance(double distance, double direction, double offset, PIDvalues values, MotionData data, uint32_t timeout);

    void moveDistance2(double distance, double direction, double jerk);
};

#endif