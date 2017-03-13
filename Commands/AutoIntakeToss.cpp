#include "AutoIntakeToss.h"

AutoIntakeToss::AutoIntakeToss() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::intakeGear.get());
	SetTimeout(1.000);
}

// Called just before this Command runs the first time
void AutoIntakeToss::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void AutoIntakeToss::Execute() {
	Wait(0.75);
	Robot::intakeGear->GetGear();

}

// Make this return true when this Command no longer needs to run execute()
bool AutoIntakeToss::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void AutoIntakeToss::End() {
	Robot::intakeGear->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoIntakeToss::Interrupted() {

}
