#ifndef Claw_H
#define Claw_H

#include <Commands/Subsystem.h>
#include"Utils/Piston.h"

class Claw : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Piston* piston;

public:
	Claw();
	void InitDefaultCommand();
	void Toggle();
	void InitHardware();
};

#endif  // Claw_H
