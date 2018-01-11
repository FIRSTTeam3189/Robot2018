#include "DrivetrainTankDrive.h"

DrivetrainTankDrive::DrivetrainTankDrive() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(drivetrain.get());
}

// Called just before this Command runs the first time
void DrivetrainTankDrive::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void DrivetrainTankDrive::Execute() {
	drivetrain.Drive(oi.GetRightY(), oi.GetLeftY());
}

// Make this return true when this Command no longer needs to run execute()
bool DrivetrainTankDrive::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DrivetrainTankDrive::End() {
	drivetrain.Drive(0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DrivetrainTankDrive::Interrupted() {
	drivetrain.Drive(0,0);
;}
