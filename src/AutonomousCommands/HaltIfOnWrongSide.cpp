#include <AutonomousCommands/HaltIfOnWrongSide.h>

HaltIfOnWrongSide::HaltIfOnWrongSide(char side_) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	side = side_;
}

// Called just before this Command runs the first time
void HaltIfOnWrongSide::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void HaltIfOnWrongSide::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool HaltIfOnWrongSide::IsFinished() {
	std::string state = DriverStation::GetInstance().GetGameSpecificMessage();
	return state[0] == side;
}

// Called once after isFinished returns true
void HaltIfOnWrongSide::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void HaltIfOnWrongSide::Interrupted() {

}
