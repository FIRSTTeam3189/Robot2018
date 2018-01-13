#include "TankDriveWithJoystick.h"

TankDriveWithJoystick::TankDriveWithJoystick() :
	CommandBase("TankDriveWithJoystick") {
	Requires(drivetrain.get());
}

void TankDriveWithJoystick::Initialize(){

}

// Called repeatedly when this Command is scheduled to run
void TankDriveWithJoystick::Execute() {
	drivetrain->Drive(oi->GetLeftY(), oi->GetRightY());
}

// Make this return true when this Command no longer needs to run execute()
bool TankDriveWithJoystick::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void TankDriveWithJoystick::End() {
	drivetrain->Stop();
}

// Called once after the command is interupted
void TankDriveWithJoystick::Interrupted() {
	drivetrain->Stop();
}
