#include "main.h"
#include "util/sensors.hpp"


/**
 * @brief 
 * 
 * @return double imu in degrees
 */
double getIMU(){
    return gyro.get_yaw();
}

/**
 * @brief Get the Average Left Rotation object (360 degree)
 * 
 * @return double 
 */
double getAverageLeftRotation(){
    return (lf.getPosition() + lb.getPosition())/2;
}

/**
 * @brief Get the Average Right Rotation object (360 degree)
 * 
 * @return double 
 */
double getAverageRightRotation(){
    return (rb.getPosition() + rf.getPosition())/2;
}
