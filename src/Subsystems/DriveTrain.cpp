// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Commands/JoyDrive.h"

#include "DriveTrain.h"
#include "../RobotMap.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS


DriveTrain::DriveTrain() : Subsystem("DriveTrain") {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    leftFront = RobotMap::driveTrainLeftFront;
    leftBack = RobotMap::driveTrainLeftBack;
    rightFront = RobotMap::driveTrainRightFront;
    rightBack = RobotMap::driveTrainRightBack;
    robotDrive = RobotMap::driveTrainRobotDrive;
    compressor = RobotMap::driveTrainCompressor;
    ultrasonic = RobotMap::driveTrainUltrasonic;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

    //Gyro
    gyro = RobotMap::driveTrainGyro;

    //for DriveTrain
    drive_x = 0;
    drive_y = 0;

    //variables for Gyro
    power = .750;
    kP = -.030;
    AutoTime = 5.50;
    Delay = .000;
    turnAngle = -60;

    pos = false;
    ShipPos = "R";

}

void DriveTrain::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND

        SetDefaultCommand(new JoyDrive());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}


void DriveTrain::JoystickDrive(std::shared_ptr<Joystick> joy)
{
	drive_x = joy->GetX() /* * .75*/;
	drive_y = joy->GetY() /* * .75*/;
	leftFront->Set(pow(drive_x, 3) + pow(-drive_y, 3));
	leftBack->Set(pow(drive_x, 3) + pow(-drive_y, 3));
	rightFront->Set(pow(drive_x, 3) + pow(drive_y, 3));
	rightBack->Set(pow(drive_x, 3) + pow(drive_y, 3));
}

void DriveTrain::Stop()
{
	robotDrive->Drive(0,0);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

double DriveTrain::GetPower()
{
	power = SmartDashboard::GetNumber("GyroDrivePower", power);
	return power;
}

double DriveTrain::GetkP()
{
	kP = SmartDashboard::GetNumber("kP", kP);
	return kP;
}

double DriveTrain::GetDelay()
{
	Delay = SmartDashboard::GetNumber("Auto Delay", Delay);
	return Delay;
}

std::string DriveTrain::GetDirection()
{
	ShipPos = SmartDashboard::GetString("Shis is", ShipPos);
	return ShipPos;
}

double DriveTrain::TurnAngle()
{
	turnAngle = SmartDashboard::GetNumber("Turn Angle", turnAngle);
	return turnAngle;
}

double DriveTrain::DisplayAngle()
{
	return gyro->GetAngle();
}

void DriveTrain::ResetGyro()
{
	gyro->Reset();
}

double DriveTrain::GetDistance()
{
	return ultrasonic->GetAverageVoltage() * 9.766 * 12;
}

bool DriveTrain::GetPos()
{
	return pos;
}
