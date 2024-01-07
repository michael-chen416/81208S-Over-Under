#include "main.h"
bool counter = true;
// purpose is to check whether 
void updatePneumatics()
{
    if (leftButton.changedToPressed())
    {
        toggleLeftWing();
    }
    if (rightButton.changedToPressed())
    {
        toggleRightWing();
    }
    if (downButton.changedToPressed())
    {
        toggleLeftRearWing();
    }
    if (upButton.changedToPressed())
    {
        toggleRightRearWing();
    }
    if (AButton.changedToPressed())
    {
        toggleBlocker();
    }
    if (YButton.changedToPressed())
    {
        toggleSingleUse();
    }
    if (XButton.changedToPressed())
    {
        //toggleFree();
    }
}

/**
 * @brief opens the wing
 *
 */
void openLeftWing()
{
    leftWing.set_value(true);
    leftWingState = true;
}

/**
 * @brief opens the wing
 *
 */
void openRightWing()
{
    rightWing.set_value(true);
    rightWingState = true;
}

/**
 * @brief closes the wing
 *
 */
void closeLeftWing()
{
    leftWing.set_value(false);
    leftWingState = false;
}

/**
 * @brief closes the wing
 *
 */
void closeRightWing()
{
    rightWing.set_value(false);
    rightWingState = false;
}

/**
 * @brief toggles the wing
 *
 */
void toggleLeftWing()
{
    if (leftWingState == false)
    {
        leftWing.set_value(true);
        leftWingState = true;
    }
    else
    {
        leftWing.set_value(false);
        leftWingState = false;
    }
}

/**
 * @brief toggles the wing
 *
 */
void toggleRightWing()
{
    if (rightWingState == false)
    {
        openRightWing();
    }
    else
    {
        closeRightWing();
    }
}

/**
 * @brief opens the wing
 *
 */
void openLeftRearWing()
{
    leftRearWing.set_value(true);
    leftRearWingState = true;
}

/**
 * @brief opens the wing
 *
 */
void openRightRearWing()
{
    rightRearWing.set_value(true);
    rightRearWingState = true;
}

/**
 * @brief closes the wing
 *
 */
void closeLeftRearWing()
{
    leftRearWing.set_value(false);
    leftRearWingState = false;
}

/**
 * @brief closes the wing
 *
 */
void closeRightRearWing()
{
    rightRearWing.set_value(false);
    rightRearWingState = false;
}

/**
 * @brief toggles the wing
 *
 */
void toggleLeftRearWing()
{
    if (leftWingState == false)
    {
        openLeftRearWing();
    }
    else
    {
        closeLeftRearWing();
    }
}

/**
 * @brief toggles the wing
 *
 */
void toggleRightRearWing()
{
    if (rightWingState == false)
    {
        openRightRearWing();
    }
    else
    {
        closeRightRearWing();
    }
}

/**
 * @brief extend Blocker
 *
 */
void extendBlocker()
{
    blocker.set_value(true);
    blockerState = true;
}

/**
 * @brief retract Blocker
 *
 */
void retractBlocker()
{
    blocker.set_value(false);
    blockerState = false;
}

/**
 * @brief toggle Blocker
 *
 */
void toggleBlocker()
{
    if (blockerState == false)
    {
        extendBlocker();
    }
    else
    {
        retractBlocker();
    }
}

/**
 * @brief extend singleUse
 *
 */
void extendSingleUse()
{
    singleUse.set_value(false);
    singleUseState = true;
}

/**
 * @brief retract singleUse
 *
 */

void retractSingleUse()
{
    singleUse.set_value(true);
    singleUseState = false;
}

/**
 * @brief toggle singleUse
 *
 */
void toggleSingleUse()
{
    if (singleUseState == false)
    {
        extendSingleUse();
    }
    else
    {
        retractSingleUse();
    }
}

/**
 * @brief extend free
 *
 */
void extendFree()
{
    Free.set_value(false);
    singleUseState = true;
}

/**
 * @brief retract free
 *
 */

void retractFree()
{
    singleUse.set_value(true);
    singleUseState = false;
}

/**
 * @brief toggle free
 *
 */
void toggleFree()
{
    if (singleUseState == false)
    {
        extendSingleUse();
    }
    else
    {
        retractSingleUse();
    }
}