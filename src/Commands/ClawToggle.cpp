#include "ClawToggle.h"

ClawToggle::ClawToggle() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(CommandBase::claw.get());
}

// Called just before this Command runs the first time
void ClawToggle::Initialize() {
	CommandBase::claw->Toggle();
}

// Called repeatedly when this Command is scheduled to run
void ClawToggle::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool ClawToggle::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void ClawToggle::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ClawToggle::Interrupted() {

}
