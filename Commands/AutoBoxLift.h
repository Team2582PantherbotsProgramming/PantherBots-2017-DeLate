#ifndef AutoBoxLift_H
#define AutoBoxLift_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class AutoBoxLift : public frc::Command {
public:
	AutoBoxLift();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // AutoBoxLift_H
