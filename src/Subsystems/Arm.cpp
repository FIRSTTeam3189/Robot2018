#include "Subsystems/Arm.h"
#include "Constants.h"
#include "../RobotMap.h"

Arm::Arm() : Subsystem("arm") {

}

void Arm::InitDefaultCommand() {

	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void Arm::ControlShoulder(double power){
	shoulderMotor->Set(ControlMode::PercentOutput, power);
}
void Arm::ControlElbow(double power){
	elbowMotor->Set(ControlMode::PercentOutput, power);
}

void Arm::ControlWrist(double power) {
	wristMotor->Set(ControlMode::PercentOutput, power);
}
double Arm::GetShoulderPot(){
	return shoulderPot->Get();
}
double Arm::GetElbowPot(){
	return elbowPot->Get();

}

double Arm::GetWristPot() {
	return wristPot->Get();
}

double Arm::ShoulderToPot(double angle){
	return (((angle - SHOULDER_ANGLE_MIN)/(SHOULDER_ANGLE_MAX - SHOULDER_ANGLE_MIN))*(SHOULDER_POT_MAX - SHOULDER_ANGLE_MIN)+SHOULDER_POT_MIN);
}
double Arm::ElbowToPot(double angle){
	return(((angle - ELBOW_ANGLE_MIN)/(ELBOW_ANGLE_MAX - ELBOW_ANGLE_MIN))*(ELBOW_POT_MAX - ELBOW_POT_MIN)+ELBOW_POT_MIN);
}
void Arm::InitHardware(){
	shoulderMotor = new CANTalon(ARM_SHOULDER_MOTOR);
	elbowMotor = new CANTalon(ARM_ELBOW_MOTOR);
	wristMotor = new CANTalon(ARM_WRIST_MOTOR);
	wristPot = new Pot(WRIST_POT);
	shoulderPot = new Pot(SHOULDER_POT);
	elbowPot = new Pot(ELBOW_POT);


}
