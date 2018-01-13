#include "Claw.h"
#include "../RobotMap.h"

Claw::Claw() : Subsystem("ExampleSubsystem") {

}

void Claw::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void Claw::Toggle(){
	piston->Toggle();
}

void Claw::InitHardware(){
	piston = new Piston(CLAW_EXTEND, CLAW_RETRACT);
}
