#ifndef AutoBoxDrop_H
#define AutoBoxDrop_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class AutoBoxDrop : public frc::Command {
public:
	AutoBoxDrop();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // AutoBoxDrop_H
