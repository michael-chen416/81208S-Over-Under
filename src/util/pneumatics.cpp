#include "main.h"
bool counter = true;
//purpose is to check whether 
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
        toggleMatchLoad();
    }
    if (upButton.changedToPressed())
    {
        toggleHangMech();
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
        openLeftWing();
    }
    else
    {
        closeLeftWing();
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
 * @brief extend matchload
 *
 */
void extendMatchload()
{
    matchloadBar.set_value(true);
    matchloadState = true;
}

/**
 * @brief retract matchload
 *
 */
void retractMatchload()
{
    matchloadBar.set_value(false);
    matchloadState = false;
}

/**
 * @brief toggle matchload
 *
 */
void toggleMatchLoad()
{
    if (matchloadState == false)
    {
        extendMatchload();
    }
    else
    {
        retractMatchload();
    }
}

/**
 * @brief extend hook
 *
 */
void extendHangMech()
{
    hangBar.set_value(false);
    climbingState = true;
}

/**
 * @brief retract hook
 *
 */

void retractHangMech()
{
    hangBar.set_value(true);
    climbingState = false;
}

/**
 * @brief toggle hook
 *
 */
void toggleHangMech()
{
    if (climbingState == false)
    {
        extendHangMech();
    }
    else
    {
        retractHangMech();
    }
}