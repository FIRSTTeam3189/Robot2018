#include "WristLift.h"

WristLift::WristLift() {
	Requires(CommandBase::wrist.get());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void WristLift::Initialize() {
wrist->PistonThingyExtend();
}

// Called repeatedly when this Command is scheduled to run
void WristLift::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool WristLift::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void WristLift::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WristLift::Interrupted() {

}
