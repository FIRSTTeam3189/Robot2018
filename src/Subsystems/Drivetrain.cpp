#include "Drivetrain.h"
#include "../RobotMap.h"
Drivetrain::Drivetrain() : Subsystem("Drivetrain") {

}

void Drivetrain::InitDefaultCommand() {
	SetDefaultCommand(new DrivetrainTankDrive());
}

void Drivetrain::Drive(double right, double left) {
	RightMotor->Set(right);
	LeftMotor->Set(left);
}

void Drivetrain::InitHardware() {
	RightMotor = new CANTalon(RobotMap.DRIVE_RIGHT);
	RightFollower = new CANTalon(RobotMap.DRIVE_RIGHT_FOLLOWER_1);
	LeftMotor = new CANTalon(RobotMap.DRIVE_LEFT);
	LeftFollower = new CANTalon(RobotMap.DRIVE_LEFT_FOLLOWER_1);
	RightFollower2 = new CANTalon(RobotMap.DRIVE_RIGHT_FOLLOWER_2);
	LeftFollower2 = new CANTalon(RobotMap.DRIVE_LEFT_FOLLOWER_2);

	LeftMotor->SetInverted(true);
	LeftFollower->SetInverted(true);
	LeftFollower2->SetInverted(true);

	RightFollower->Set(RightMotor->GetDeviceID());
	LeftFollower->Set(LeftMotor->GetDeviceID());
    RightFollower2->Set(RightMotor->GetDeviceID());
    LeftFollower2->Set(LeftMotor->GetDeviceID());
}
