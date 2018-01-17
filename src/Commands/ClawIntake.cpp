#include "ClawIntake.h"

ClawIntake::ClawIntake() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());

	Requires(CommandBase::claw.get()); //woah we did it, now we have SOMETHING that does NOTHING .
}

// Called just before this Command runs the first time
void ClawIntake::Initialize() {
	CommandBase::claw->SetPower(0.5); //So basically we're intimidating a gay prostitute - JT Cobbs, 2018.
}

// Called repeatedly when this Command is scheduled to run
void ClawIntake::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool ClawIntake::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ClawIntake::End() {
	(CommandBase::claw->SetPower(0)); //we considered going way faster. Can't stop won't stop
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ClawIntake::Interrupted() {
	End();
}
