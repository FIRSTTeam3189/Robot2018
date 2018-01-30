#include "Claw.h"
#include "../RobotMap.h"

Claw::Claw() :
		Subsystem("ExampleSubsystem") {

}

void Claw::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands

void Claw::SetPower(double power) {
	Right->Set(ControlMode::PercentOutput, power);
}

void Claw::ClawOpen() {
	TheOneTheOnlyThePiston->Extend();

}

void Claw::ClawClose(){
	TheOneTheOnlyThePiston->Retract();

}

void Claw::ClawToggle(){
	TheOneTheOnlyThePiston->Toggle();

}
void Claw::InitHardware() {
	Left = new CANTalon(LEFT_CLAW_MOTOR);
	Right = new CANTalon(RIGHT_CLAW_MOTOR);

	TheOneTheOnlyThePiston = new Piston(CLAW_EXTEND, CLAW_RETRACT, false);

	Left->SetInverted(true);
	Left->Set(ControlMode::Follower, Right->GetDeviceID());

}
