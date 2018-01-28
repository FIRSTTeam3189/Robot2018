#include "ClawOuttake.h"

ClawOuttake::ClawOuttake() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(CommandBase::claw.get());
}

// Called just before this Command runs the first time
void ClawOuttake::Initialize() {
	claw->SetPower(CLAW_OUTAKE_POWER);
	claw->ClawClose();

}

// Called repeatedly when this Command is scheduled to run
void ClawOuttake::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool ClawOuttake::IsFinished() {
	return false;
	//Expected to run while held.
}

// Called once after isFinished returns true
void ClawOuttake::End() {
	claw->SetPower(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ClawOuttake::Interrupted() {
	End();
}
