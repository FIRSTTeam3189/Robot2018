#include "Wrist.h"
#include "../RobotMap.h"
#include "Constants.h"
#include "../RobotMap.h"
#include <math.h>
#include <SmartDashboard/SmartDashboard.h>

Wrist::Wrist() : Subsystem("wrist") {

}

void Wrist::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

double Wrist::GetWristPot() {
	return wristPot->Get();
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
void Wrist::ControlWrist(double power) {
	wristMotor->Set(ControlMode::PercentOutput, power);
}
void Wrist::InitHardware(){
	wristMotor = new CANTalon(ARM_WRIST_MOTOR);
	wristPot = new Pot(WRIST_POT);
}
