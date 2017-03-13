/*
 *
 *#include "AlignWithPeg.h"
#include "AlignPIDWrapper.h"

#include <Preferences.h>

AlignWithPeg::AlignWithPeg(frc::JoystickButton* abortBtn)
{
	Requires(Robot::driveTrain.get());
	Requires(Robot::visionManager.get());

	//frc::Preferences* prefs = oi.get()->GetPrefs();

	//frc::Preferences* prefs;
	//prefs = frc::Preferences::GetInstance();

	AlignPIDWrapper* pidSO = new AlignPIDWrapper();

	m_pid = new frc::PIDController(
			1.000,
			0.000,
			0.000,
			pidSO,
			pidSO);

	m_abortBtn = abortBtn;
}

AlignWithPeg::~AlignWithPeg()
{
	delete m_pid;
}

void AlignWithPeg::Initialize()
{
	m_pid->SetTolerance(.1);
	//drive.get()->SetTalonMode(CANSpeedController::kPosition);
}

void AlignWithPeg::Execute()
{
	m_pid->SetSetpoint(0);
}

bool AlignWithPeg::IsFinished()
{
	return m_pid->OnTarget() && frc::SmartDashboard::GetNumber("Distance", -2);
}

void AlignWithPeg::End()
{
}

void AlignWithPeg::Interrupted()
{
}
*/
