#ifndef AutoGearIntake_H
#define AutoGearIntake_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class AutoGearIntake : public frc::Command {
public:
	AutoGearIntake();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	bool GearObtained();

private:

};

#endif  // AutoGearIntake_H
