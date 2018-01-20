#include "ArmGoToPoint.h"
#include <math.h>

ArmGoToPoint::ArmGoToPoint(double x, double y) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(CommandBase::arm.get());
	double length = sqrt(pow(x,2)+pow(y,2));
	this-> shoulderAngle = acos((pow(length,2) + pow(ARM_ONE_LENGTH,2) - pow(ARM_TWO_LENGTH,2))/2*length*ARM_ONE_LENGTH);
	this-> elbowAngle = (length*sin(shoulderAngle))/ARM_TWO_LENGTH;
}

// Called just before this Command runs the first time.
void ArmGoToPoint::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ArmGoToPoint::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool ArmGoToPoint::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ArmGoToPoint::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
//Hitler did nothing wrong, james agrees
void ArmGoToPoint::Interrupted() {

}
