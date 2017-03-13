#include "AutoGearIntake.h"

AutoGearIntake::AutoGearIntake() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::intakeGear.get());
}

// Called just before this Command runs the first time
void AutoGearIntake::Initialize() {
	//laserFinish = Robot::intakeGear->LaserInfo();
}

// Called repeatedly when this Command is scheduled to run
void AutoGearIntake::Execute() {
	Robot::intakeGear->GetGear();

}

// Make this return true when this Command no longer needs to run execute()
bool AutoGearIntake::IsFinished() {
	return Robot::intakeGear->LaserInfo();
}

// Called once after isFinished returns true
void AutoGearIntake::End() {
	Robot::intakeGear->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoGearIntake::Interrupted() {
	Robot::intakeGear->Stop();
}
