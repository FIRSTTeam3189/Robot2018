#include "SendData.h"

SendData::SendData(double seconds) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(CommandBase::vision.get());
	SetTimeout(seconds);
}

// Called just before this Command runs the first time
void SendData::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void SendData::Execute() {
	CommandBase::vision->SendData();
}

// Make this return true when this Command no longer needs to run execute()
bool SendData::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void SendData::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SendData::Interrupted() {

}
