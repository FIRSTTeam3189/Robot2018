#include <Joystick.h>
#include <LiveWindow/LiveWindow.h>
#include <Subsystems/Drivetrain.h>
#include <SmartDashboard/SmartDashboard.h>

#include "Commands/TankDriveWithJoystick.h"
#include "RobotMap.h"

Drivetrain::Drivetrain() :
	frc::Subsystem("Drivetrain") {

}

/**
 * When no other command is running let the operator drive around
 * using the PS3 joystick.
 */
void Drivetrain::InitDefaultCommand() {
	SetDefaultCommand(new TankDriveWithJoystick());
}

/**
 * The log method puts interesting information to the SmartDashboard.
 */
void Drivetrain::Log() {
//	SmartDashboard::PutNumber("Left Speed", leftEncoder.GetRate());
//	SmartDashboard::PutNumber("Right Speed", rightEncoder.GetRate());
	SmartDashboard::PutNumber("Pot Value", GetPotValue());
}

void Drivetrain::Drive(double power){
	frontLeft->Set(ControlMode::PercentOutput, power);
	frontRight->Set(ControlMode::PercentOutput, power);
}

void Drivetrain::Drive(double left, double right) {
	frontLeft->Set(ControlMode::PercentOutput, left);
	frontRight->Set(ControlMode::PercentOutput, right);
}

void Drivetrain::Stop(){
	Drive(0, 0);
}

//NOT INMPLEMENTED
double Drivetrain::GetHeading() {
	return 0.0;
}

void Drivetrain::Reset() {
	/*gyro.Reset();
	leftEncoder.Reset();
	rightEncoder.Reset();*/
}

double Drivetrain::GetDistance() {
	return 0.0;//(leftEncoder.GetDistance() + rightEncoder.GetDistance()) / 2;
}

double Drivetrain::GetDistanceToObstacle() {
	// Really meters in simulation since it's a rangefinder...
	return 0.0;//rangefinder.GetAverageVoltage();
}
double Drivetrain::GetPotValue(){
	return pot->Get();
}
void Drivetrain::InitHardware(){
	frontLeft = new CANTalon(DRIVE_LEFT_FRONT);
	middleLeft = new CANTalon(DRIVE_LEFT_MIDDLE);
	rearLeft = new CANTalon(DRIVE_LEFT_BACK);
	frontRight = new CANTalon(DRIVE_RIGHT_FRONT);
	middleRight = new CANTalon(DRIVE_RIGHT_MIDDLE);
	rearRight = new CANTalon(DRIVE_RIGHT_BACK);

	frontLeft->SetInverted(true);
	middleLeft->SetInverted(true);
	rearLeft->SetInverted(true);

	middleLeft->Set(ControlMode::Follower, frontLeft->GetDeviceID());
	rearLeft->Set(ControlMode::Follower, frontLeft->GetDeviceID());
	middleRight->Set(ControlMode::Follower, frontRight->GetDeviceID());
	rearRight->Set(ControlMode::Follower, frontRight->GetDeviceID());
}
