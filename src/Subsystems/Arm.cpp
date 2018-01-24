#include "Subsystems/Arm.h"
#include "Constants.h"
#include "../RobotMap.h"
#include <math.h>
#include <SmartDashboard/SmartDashboard.h>
Arm::Arm() :
		Subsystem("arm") {

}

void Arm::InitDefaultCommand() {

	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
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

void Arm::armPosition(double x, double y, double angles[3]) {
	/* Useless old math.
	double c = sqrt(x * x + y * y);
	double alpha = acos(
			((ARM_ONE_LENGTH * ARM_ONE_LENGTH)
					+ (ARM_TWO_LENGTH * ARM_TWO_LENGTH) - (c * c)) / 2
					* ARM_ONE_LENGTH * ARM_TWO_LENGTH);
	double B = asin(ARM_TWO_LENGTH * sin(alpha) / c);
	double D = acos(x >= ARM_SWITCH ? x : -x / c);
	double theta2 = (B + D);
	//"Calculus is gay." -Nick M. (January 20, 2018)
	if (x >= ARM_SWITCH) theta2 = M_PI - theta2;
	double theta1 = M_PI - alpha;
	if (x >= ARM_SWITCH) -theta1;
	angles[0] = theta1;
	angles[1] = theta2;

	frc::SmartDashboard::PutNumber("theta1", theta1);
	frc::SmartDashboard::PutNumber("theta2", theta2);
	*/
	double wristX = x - ARM_THREE_LENGTH*cos(phi);
	double wristY= y - ARM_THREE_LENGTH*sin(phi);
	double c2 = ((wristX*wristX) + (wristY*wristY)-(ARM_ONE_LENGTH*ARM_ONE_LENGTH)-(ARM_TWO_LENGTH*ARM_TWO_LENGTH))/ (2*ARM_ONE_LENGTH)*(ARM_TWO_LENGTH);
	double s2 = -sqrt(1-(c2*c2));
	double s1 = ((((((ARM_ONE_LENGTH + ARM_TWO_LENGTH*c2)*wristY)-ARM_TWO_LENGTH)*s2)*wristX))/((wristX*wristX)+(wristY*wristY));
	double c1 = ((((((ARM_ONE_LENGTH + ARM_TWO_LENGTH*c2)*wristX) + ARM_TWO_LENGTH)*s2)*wristY))/((wristX*wristX)+(wristY*wristY));
	double theta1 = atan2(s1,c1);
	double theta2 = atan2(s2,c2);
	double theta3 = phi-theta1-theta2;

	frc::SmartDashboard::PutNumber("theta1: ", theta1);
	frc::SmartDashboard::PutNumber("theta2: ", theta2);
	frc::SmartDashboard::PutNumber("theta3: ", theta3);

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
