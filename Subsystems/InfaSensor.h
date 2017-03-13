#ifndef InfaSensor_H
#define InfaSensor_H

#include <Commands/Subsystem.h>

class InfaSensor : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

public:
	InfaSensor();
	void InitDefaultCommand();
};

#endif  // InfaSensor_H
