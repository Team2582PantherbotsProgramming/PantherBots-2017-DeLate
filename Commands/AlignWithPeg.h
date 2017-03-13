#ifndef ALIGN_WITH_PEG_H
#define ALIGN_WITH_PEG_H

#include "Commands/Subsystem.h"
#include "../Subsystems/DriveTrain.h"
#include "../Subsystems/VisionManager.h"
#include "Robot.h"

#include <PIDController.h>

// Summary:
//
class AlignWithPeg : public Command
{
private:
	frc::PIDController* m_pid;

	frc::JoystickButton* m_abortBtn;

public:
	AlignWithPeg(frc::JoystickButton*);
	~AlignWithPeg();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif // ALIGN_WITH_PEG_H
