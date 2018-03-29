#include <AutonomousCommands/DriveEncoders.h>

DriveEncoders::DriveEncoders(double _power, enum DriveDirection _dir, double _distance) {
	Requires(CommandBase::drivetrain.get());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	power = _power;
	dir = _dir;
	distance = _distance;
}

// Called just before this Command runs the first time
void DriveEncoders::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void DriveEncoders::Execute() {
	drivetrain->DriveEncoders(power, dir);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveEncoders::IsFinished() {
	return distance >= drivetrain->GetDistanceInInches ();// ? true : false;
}

// Called once after isFinished returns true
void DriveEncoders::End() {
	drivetrain->Drive(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveEncoders::Interrupted() {
	drivetrain->Drive(0);
}
