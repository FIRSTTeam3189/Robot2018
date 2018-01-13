#include "TankDriveWithLimit.h"

TankDriveWithLimit::TankDriveWithLimit() {
	Requires(CommandBase::drivetrain.get());

	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void TankDriveWithLimit::Initialize() {
	CommandBase::drivetrain->Stop();
	//CommandBase::drivetrain->Drive(0,0)

}

// Called repeatedly when this Command is scheduled to run
void TankDriveWithLimit::Execute() {
	auto potValue=CommandBase::drivetrain->GetPotValue()/static_cast<double>(1023);
	auto leftY=CommandBase::oi->GetLeftY()*potValue;
	auto rightY=CommandBase::oi->GetRightY()*potValue;
	CommandBase::drivetrain->Drive(leftY, rightY);
}

// Make this return true when this Command no longer needs to run execute()
bool TankDriveWithLimit::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void TankDriveWithLimit::End() {
	CommandBase::drivetrain->Stop();

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TankDriveWithLimit::Interrupted() {
	CommandBase::drivetrain->Stop();
}
