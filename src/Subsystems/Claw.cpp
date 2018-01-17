#include "Claw.h"
#include "../RobotMap.h"

Claw::Claw() : Subsystem("ExampleSubsystem") {

}

void Claw::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands

void Claw::SetPower(double power){
	Right->Set(ControlMode::PercentOutput, power);
}

void Claw::InitHardware(){
	Left= new CANTalon();
	Right= new CANTalon();

	Left->SetInverted(true);
	Left->Set(ControlMode::Follower, Right->GetDeviceID());

}
