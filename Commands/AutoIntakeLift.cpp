#include "AutoIntakeLift.h"

AutoIntakeLift::AutoIntakeLift() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::moveIntake.get());
	SetTimeout(1.0);

}

// Called just before this Command runs the first time
void AutoIntakeLift::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void AutoIntakeLift::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool AutoIntakeLift::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void AutoIntakeLift::End() {
	Robot::moveIntake->UpIntake();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoIntakeLift::Interrupted() {

}
