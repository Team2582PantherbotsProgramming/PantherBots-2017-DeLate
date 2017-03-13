#ifndef AutoIntakeDrop_H
#define AutoIntakeDrop_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class AutoIntakeDrop : public frc::Command {
public:
	AutoIntakeDrop();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // AutoIntakeDrop_H
