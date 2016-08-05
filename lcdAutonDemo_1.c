/*-----------------------------------------------------------------------------*/
/*  LCD autonomous demo 1                                                      */
/*  Copyright (c) 2013 James Pearman                                           */
/*  This is unlicensed software - you may modofy and use as you wish           */
/*-----------------------------------------------------------------------------*/

//Competition Control and Duration Settings
#pragma competitionControl(Competition)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

// Include the lcd button get utility function
#include "getlcdbuttons.c"

// global hold the auton selection
static int MyAutonomous = 0;

/*-----------------------------------------------------------------------------*/
/*  Display autonomous selection                                               */
/*-----------------------------------------------------------------------------*/
void
LcdSetAutonomous( int value )
{
    // Simple selection display
    if( value == 0 ) {
        displayLCDString(0, 0, "auton 0");
        displayLCDString(1, 0, "[00]   01    02 ");
        }
    if( value == 1 ) {
        displayLCDString(0, 0, "auton 1");
        displayLCDString(1, 0, " 00   [01]   02 ");
        }
    if( value == 2 ) {
        displayLCDString(0, 0, "auton 2");
        displayLCDString(1, 0, " 00    01   [02]");
        }

    // Save autonomous mode for later
    MyAutonomous = value;
}

/*-----------------------------------------------------------------------------*/
/*  Select one of three autonomous choices                                     */
/*-----------------------------------------------------------------------------*/

void
LcdAutonomousSelection()
{
    TControllerButtons  button;

    // Clear LCD and turn on backlight
    clearLCDLine(0);
    clearLCDLine(1);
    bLCDBacklight = true;

    // diaplay default choice
    LcdSetAutonomous(0);

    while( bIfiRobotDisabled )
        {
        // this function blocks until button is pressed
        button = getLcdButtons();

        // Display and select the autonomous routine
        if( button == kButtonLeft )
            LcdSetAutonomous(0);

        if( button == kButtonCenter )
            LcdSetAutonomous(1);

        if( button == kButtonRight )
            LcdSetAutonomous(2);

        // Don't hog the cpu !
        wait1Msec(10);
        }
}

void pre_auton()
{
    bStopTasksBetweenModes = true;

    LcdAutonomousSelection();
}

task autonomous()
{
    switch( MyAutonomous ) {
        case    0:
            // run auton code
            break;

        case    1:
            // run some other auton code
            break;

        default:
            break;
        }
}

task usercontrol()
{
    while (true) {
        wait1Msec(10);
        }
}
