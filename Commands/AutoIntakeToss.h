#ifndef AutoIntakeToss_H
#define AutoIntakeToss_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class AutoIntakeToss : public frc::Command {
public:
	AutoIntakeToss();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // AutoIntakeToss_H
