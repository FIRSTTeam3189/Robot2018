#include "PingVision.h"

PingVision::PingVision() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(CommandBase::vision.get());
}

// Called just before this Command runs the first time
void PingVision::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void PingVision::Execute() {
	CommandBase::vision->ReceiveData();
}

// Make this return true when this Command no longer needs to run execute()
bool PingVision::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void PingVision::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PingVision::Interrupted() {

}
