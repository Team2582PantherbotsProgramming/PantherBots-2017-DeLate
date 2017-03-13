// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.



#include "Robot.h"
//#include "Robot.cpp"
#include "IntakeGear.h"
#include "../RobotMap.h"
using namespace std;
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

IntakeGear::IntakeGear() : Subsystem("IntakeGear") {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    topRoller = RobotMap::intakeGearTopRoller;
    bottomRoller = RobotMap::intakeGearBottomRoller;
    laser = RobotMap::intakeGearLaser;
    //laserInfo = true;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    if(LaserInfo() == false)
        {
        	SmartDashboard::PutString("Gear State:", "No Gear");
        }
        else
        {
        	SmartDashboard::PutString("Gear State:", "Gear");

        }
}

void IntakeGear::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}


// Put methods for controlling this subsystem
// here. Call these from Commands.

void IntakeGear::GetGear()
{
	topRoller->Set(-.700);
	bottomRoller->Set(.700);
}


void IntakeGear::ThrowOut()
{
	topRoller->Set(1.00);
	bottomRoller->Set(-1.00);
}

void IntakeGear::Stop()
{
	topRoller->Set(0.0);
	bottomRoller->Set(0.0);
}

bool IntakeGear::LaserInfo()
{
	return !(laser->Get());
}
