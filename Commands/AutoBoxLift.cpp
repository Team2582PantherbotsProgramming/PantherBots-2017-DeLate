#include "AutoBoxLift.h"

AutoBoxLift::AutoBoxLift() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::moveBox.get());
	SetTimeout(0.5);
}

// Called just before this Command runs the first time
void AutoBoxLift::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void AutoBoxLift::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool AutoBoxLift::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void AutoBoxLift::End() {
	Robot::moveBox->UpBox();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoBoxLift::Interrupted() {

}
