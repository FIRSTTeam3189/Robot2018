#include "Subsystems/Arm.h"
#include "Constants.h"
#include "../RobotMap.h"
#include <math.h>
#include <SmartDashboard/SmartDashboard.h>
Arm::Arm() :
		Subsystem("arm") {

}

Point::Point(double x_, double y_){
	x = x_;
	y = y_;
}

void Arm::InitDefaultCommand() {

	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put functiom for controlling this subsystem
// here. Call these from Commands.
void Arm::ControlShoulder(double power) {
	shoulderMotor->Set(ControlMode::PercentOutput, power);
}
void Arm::ControlElbow(double power) {
	elbowMotor->Set(ControlMode::PercentOutput, power);
}

double Arm::GetShoulderPot() {
	return shoulderPot->Get();
}
double Arm::GetElbowPot() {
	return elbowPot->Get();

}

void Arm::GetAnglesForTarget(double x, double y, double angles[3]) {
	//get the distance between the destination and the shoulder joint(origin)
	double length = sqrt(pow(x, 2) + pow(y, 2));
	//calculate the inner elbow angle with law of cosines.
	double inner_elbow_angle = acos(
			(((ARM_TWO_LENGTH * ARM_TWO_LENGTH)
					+ (ARM_ONE_LENGTH * ARM_ONE_LENGTH) - (length * length))
					/ (2 * ARM_TWO_LENGTH * ARM_ONE_LENGTH)));
	//PI - inner_angle to get the angle the arm needs to go to.
	angles[1] = M_PI - inner_elbow_angle;
	// if the point is near the back of the bot negate the angle
	if (x >= ARM_SWITCH)
		angles[1] = -angles[1];
	//Calculate the angle between the line between shoulder(origin)
	// and destination point to go to using the law of sines with the elbow angle.
	double inner_shoulder_angle = asin(
			((ARM_TWO_LENGTH * sin(inner_elbow_angle)) / length));

	// get the unit vector of line between shoulder(origin) and destination point
	// i only do the x because the y will be multiplied out when we dot product by
	// the negative x axis vector.
	double unitx = x / (length);
	double unity = y / (length);

	// cos^-1((A * B)/|A||B|)
	// A = unit vector of line between shoulder(origin) and destination point
	// |A| = length of unit vector of line between shoulder(origin) and destination point(its 1)
	// B = unit vector going down the negative X axis
	// |B| = length of unit vector going down the negative X axis(its 1)
	double subangle = acos(ARM_SWITCH <= x ? unitx : -unity);	// this is simplifies due to a lot of the values being 1 or zero
	//Subtract PI by the angles we got above to find the angle between the Stage 1 arm and the positive X axis.
	angles[0] = ((
			y < 0 && x > ARM_SWITCH ?
					-subangle : subangle) + inner_shoulder_angle);
	if (x <= ARM_SWITCH)
		angles[0] = (3 * M_PI / 2)
				- angles[0];
}
double Arm::GetShoulderAngle(){
	return (((GetShoulderPot()-SHOULDER_POT_MIN)/(SHOULDER_POT_MAX-SHOULDER_POT_MIN))*(SHOULDER_ANGLE_MAX-SHOULDER_ANGLE_MIN)+SHOULDER_ANGLE_MIN);
}

double Arm::GetElbowAngle(){
	return(((GetElbowPot()-ELBOW_POT_MIN)/(ELBOW_POT_MAX-ELBOW_ANGLE_MIN))*(ELBOW_ANGLE_MAX-ELBOW_ANGLE_MIN)+ELBOW_ANGLE_MIN);
}

Point Arm::GetCurrentLocation() {
	return Point( ((cos(GetShoulderAngle()) * ARM_ONE_LENGTH)) + (cos(GetElbowAngle()) * ARM_TWO_LENGTH ),
			((sin(GetShoulderAngle()) * ARM_ONE_LENGTH) + ((sin(GetElbowAngle()) * ARM_TWO_LENGTH))) );
}

void Arm::GetNewPointOnLine(double x, double y, double angles[3]) {
	Point current_location = GetCurrentLocation();
	double dis = sqrt(pow(x-current_location.x, 2) + pow(y-current_location.y, 2));
	double ux = ((x-current_location.x)/(dis))+current_location.x;
	double uy = ((y-current_location.y)/(dis))+current_location.y;

	//get the distance between the destination and the shoulder joint(origin)
	double length = sqrt(pow(ux, 2) + pow(uy, 2));
	//calculate the inner elbow angle with law of cosines.
	double inner_elbow_angle = acos(
			(((ARM_TWO_LENGTH * ARM_TWO_LENGTH)
					+ (ARM_ONE_LENGTH * ARM_ONE_LENGTH) - (length * length))
					/ (2 * ARM_TWO_LENGTH * ARM_ONE_LENGTH)));
	//PI - inner_angle to get the angle the arm needs to go to.
	angles[1] = M_PI - inner_elbow_angle;
	// if the point is near the back of the bot negate the angle
	if (ux >= ARM_SWITCH)
		angles[1] = -angles[1];
	//calcultae the angle between the line between shoulder(origin)
	// and destination point to go to using the law of sines with the elbow angle.
	double inner_shoulder_angle = asin(
			((ARM_TWO_LENGTH * sin(inner_elbow_angle)) / length));

	// get the unit vector of line between shoulder(origin) and destination point
	// i only do the x because the y will be multiplied out when we dot product by
	// the negitive x axis vector.
	double unitx = ux / (length);
	double unity = uy / (length);

	// cos^-1((A * B)/|A||B|)
	// A = unit vector of line between shoulder(origin) and destination point
	// |A| = length of unit vector of line between shoulder(origin) and destination point(its 1)
	// B = unit vector going down the negitive X axis
	// |B| = length of unit vector going down the negitive X axis(its 1)
	double subangle = acos(ARM_SWITCH <= ux ? unitx : -unity);	// this is simplifies due to a lot of the values being 1 or zero
	//substract PI by the angles we got above to find the angle between the Stage 1 arm and the positive X axis.
	angles[0] = ((
			uy < 0 && ux > ARM_SWITCH ?
					-subangle : subangle) + inner_shoulder_angle);
	if (x <= ARM_SWITCH)
		angles[0] = (3 * M_PI / 2)
				- angles[0];
}

double Arm::ShoulderToPot(double angle) {
	return (((angle - SHOULDER_ANGLE_MIN)
			/ (SHOULDER_ANGLE_MAX - SHOULDER_ANGLE_MIN))
			* (SHOULDER_POT_MAX - SHOULDER_ANGLE_MIN) + SHOULDER_POT_MIN);
}
double Arm::ElbowToPot(double angle) {
	return (((angle - ELBOW_ANGLE_MIN) / (ELBOW_ANGLE_MAX - ELBOW_ANGLE_MIN))
			* (ELBOW_POT_MAX - ELBOW_POT_MIN) + ELBOW_POT_MIN);
}
void Arm::InitHardware() {
	shoulderMotor = new CANTalon(ARM_SHOULDER_MOTOR);
	elbowMotor = new CANTalon(ARM_ELBOW_MOTOR);
	shoulderPot = new Pot(SHOULDER_POT);
	elbowPot = new Pot(ELBOW_POT);

}
