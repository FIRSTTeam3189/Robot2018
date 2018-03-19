#include "Wrist.h"
#include "../RobotMap.h"
#include "Constants.h"
#include "../RobotMap.h"
#include "Commands/WristJoystickControl.h"
#include <math.h>
#include <SmartDashboard/SmartDashboard.h>

Wrist::Wrist() : Subsystem("wrist") {

}

void Wrist::InitDefaultCommand() {
	SetDefaultCommand(new WinchJoystickControl());
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

double Wrist::GetWristPot() {
	return wristPot->Get();
}

void Wrist::ControlWrist(double power) {
	wristMotor->Set(ControlMode::PercentOutput, power);
}
void Wrist::InitHardware(){
	wristMotor = new CANTalon(ARM_WRIST_MOTOR);
	wristPot = new Pot(WRIST_POT);
	wristPiston = new PistonDouble(PISTON_PISTON);
}

void Wrist::PistonThingyExtend(){
	wristPiston -> Extend();
}

void Wrist::PistonThingyRetract(){
	wristPiston -> Retract();
}

void Wrist::PistonThingyToggle(){
	wristPiston -> Toggle();
}
