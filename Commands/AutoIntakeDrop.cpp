#include "AutoIntakeDrop.h"

AutoIntakeDrop::AutoIntakeDrop() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::moveIntake.get());
	SetTimeout(0.5);
}

// Called just before this Command runs the first time
void AutoIntakeDrop::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void AutoIntakeDrop::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool AutoIntakeDrop::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void AutoIntakeDrop::End() {
	Robot::moveIntake->DownIntake();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoIntakeDrop::Interrupted() {

}
