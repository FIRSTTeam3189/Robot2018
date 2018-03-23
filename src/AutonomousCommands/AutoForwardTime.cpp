#include <AutonomousCommands/AutoForwardTime.h>

AutoForwardTime::AutoForwardTime(double seconds, double power_) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(CommandBase::drivetrain);
	SetTimeout(seconds);
	power = power_;
}

// Called just before this Command runs the first time
void AutoForwardTime::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void AutoForwardTime::Execute() {
	drivetrain->Drive(power);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoForwardTime::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void AutoForwardTime::End() {
	drivetrain->Drive(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoForwardTime::Interrupted() {
	drivetrain->Drive(0);
}
