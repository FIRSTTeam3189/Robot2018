#include <Joystick.h>
#include <LiveWindow/LiveWindow.h>
#include <Subsystems/Drivetrain.h>
#include <SmartDashboard/SmartDashboard.h>
#include "ctre/phoenix/MotorControl/FeedbackDevice.h"
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
 * The log method puts interesting information to the SmartDashboard
 */
void Drivetrain::Log() {
	SmartDashboard::PutNumber("Left Speed", frontLeft->GetMotorOutputPercent());
	SmartDashboard::PutNumber("Right Speed", frontRight->GetMotorOutputPercent());

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
	//leftEncoder->Reset();
	//rightEncoder->Reset();
}

double Drivetrain::GetDistance() {

	return (rearRight->GetSelectedSensorPosition(0) + frontLeft->GetSelectedSensorPosition(0)) / 2;
}

double Drivetrain::GetRightEncoderDistance(){
	return rearRight->GetSelectedSensorPosition(0);
}

double Drivetrain::GetLeftEncoderDistance(){
	return frontLeft->GetSelectedSensorPosition(0);
}
void Drivetrain::EngageWinch(){
	winchPiston->Extend();
}

double Drivetrain::GetDistanceToObstacle() {
	// Really meters in simulation since it's a rangefinder...
	return 0.0;//rangefinder.GetAverageVoltage();
}

void Drivetrain::InitHardware(){
	frontLeft = new CANTalon(DRIVE_LEFT_FRONT);
	rearLeft = new CANTalon(DRIVE_LEFT_BACK);
	frontRight = new CANTalon(DRIVE_RIGHT_BACK);
	rearRight = new CANTalon(DRIVE_RIGHT_FRONT);//TODO fix this on real bot(the rights are reversed)

	frontRight->SetInverted(true);
	rearRight->SetInverted(true);

	frontLeft->SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
	frontRight->SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
	rearLeft->SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
	rearRight->SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);

	rearLeft->Set(ControlMode::Follower, frontLeft->GetDeviceID());
	rearRight->Set(ControlMode::Follower, frontRight->GetDeviceID());

	winchPiston = new PistonDouble(DRIVETRAIN_PISTON);

	rearRight->ConfigSelectedFeedbackSensor(ctre::phoenix::motorcontrol::FeedbackDevice::QuadEncoder, 0, 0);
	rearRight->SetSensorPhase(false);
	frontLeft->ConfigSelectedFeedbackSensor(ctre::phoenix::motorcontrol::FeedbackDevice::QuadEncoder, 0, 0);
	frontLeft->SetSensorPhase(false);

	//leftEncoder = new Encoder(LEFT_ENCODER1);
	//rightEncoder = new Encoder(RIGHT_ENCODER1);
}
