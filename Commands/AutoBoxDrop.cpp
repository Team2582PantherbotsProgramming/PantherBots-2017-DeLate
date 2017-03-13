#include "AutoBoxDrop.h"

AutoBoxDrop::AutoBoxDrop() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::moveBox.get());
	SetTimeout(.1);

}

// Called just before this Command runs the first time
void AutoBoxDrop::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void AutoBoxDrop::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool AutoBoxDrop::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void AutoBoxDrop::End() {
		Robot::moveBox->DownBox();

}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoBoxDrop::Interrupted() {

}
