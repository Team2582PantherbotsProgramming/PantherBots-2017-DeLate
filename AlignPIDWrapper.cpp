///////////////////////////////////////////////////////////////////////////////
//
// AlignPIDWrapper.cpp
//
//  Created on: Feb 16, 2017
//     Author: Silas A.
//
///////////////////////////////////////////////////////////////////////////////

#include <AlignPIDWrapper.h>
#include <SmartDashboard/SmartDashboard.h>
//#include "CommandBase.h"
#include "Commands/Subsystem.h"

AlignPIDWrapper::AlignPIDWrapper()
{
	// Uses DriveTrain
}

double AlignPIDWrapper::PIDGet()
{
	return frc::SmartDashboard::GetNumber("CenterX", -2);
}

void AlignPIDWrapper::PIDWrite(double output)
{
	Robot::driveTrain.get()->robotDrive->Drive(.4, output);
}
