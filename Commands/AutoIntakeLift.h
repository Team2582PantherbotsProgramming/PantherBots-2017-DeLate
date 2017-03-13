#ifndef AutoIntakeLift_H
#define AutoIntakeLift_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class AutoIntakeLift : public frc::Command {
public:
	AutoIntakeLift();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:

};

#endif  // AutoIntakeLift_H
