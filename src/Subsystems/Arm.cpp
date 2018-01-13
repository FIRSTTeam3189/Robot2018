#include "../../../../git/Robot2018/src/Subsystems/Arm.h"

#include "../RobotMap.h"

Arm::Arm() : Subsystem("arm") {

}

void Arm::InitDefaultCommand() {

	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void Arm::ControlArm(double power){
	motor->Set(ControlMode::PercentOutput, power);
}

void Arm::InitHardware(){
	motor = new CANTalon(ARM_MOTOR);
}
