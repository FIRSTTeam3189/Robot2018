#ifndef Arm_H
#define Arm_H

#include <Commands/Subsystem.h>
#include <ctre/phoenix/MotorControl/CAN/TalonSRX.h>
#include <ctre/phoenix/MotorControl/ControlMode.h>
#include <SmartDashboard/SmartDashboard.h>
#include <AnalogPotentiometer.h>
#include "RobotMap.h"

using CANTalon = ctre::phoenix::motorcontrol::can::TalonSRX;
using ControlMode = ctre::phoenix::motorcontrol::ControlMode;
using Pot = AnalogPotentiometer;

struct Point{
public:
	Point(double x, double y);
	double x;
	double y;
};

class Arm: public frc::Subsystem {
private:

	CANTalon* shoulderMotor;
	CANTalon* elbowMotor;
	Pot* elbowPot; //= Pot(ELBOW_POT, 359, 0);
	Pot* shoulderPot; // = Pot(SHOULDER_POT, 359, 0);

	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

public:
	Arm();
	/**
	 * returns the Current location for the wrist in x y coordinates
	 */
	Point GetCurrentLocation();//TODO make this.
	/**
	 * returns the current angles of the shoulder
	 */
	double GetShoulderAngle();//TODO make this
	/**
	 * returns the current angles of the elbow
	 */
	double GetElbowAngle();//TODO make this
	/**
	 * returns angles required for the x y coordinates given returns angles in given double array
	 */
	void GetAnglesForTarget(double x, double y, double angles[2]);
	/**
	 * returns angles required for a close point to current along the line to destination coordinates
	 */
	void GetNewPointOnLine(double x, double y, double angles[2]);
	void InitDefaultCommand();
	/**
	 * controls the shoulder motor of the arm
	 * @param power in range from -1 to 1
	 */
	void ControlShoulder(double power);
	/**
	 * controls the elbow motor of the arm
	 * @param power in range from -1 to 1
	 */
	void ControlElbow(double power);
	/**
	 * gets the value for the potentiometer on the shoulder motor
	 * @returns value from 0 to 1023
	 */

	double GetShoulderPot();
	/**
	 * gets the value for the potentiometer on the elbow motor
	 * @returns value from 0 to 1023
	 */

	double GetElbowPot();
	//
	/**
	 * get
	 * finds percent of the total span from 0-1 then finds the potentiometer value for the given angle value
	 * @param angle in radians of angle value
	 * @return the equivalent potentiometer value for the given angle value
	 */
	double ShoulderToPot(double angle);
	double ElbowToPot(double angle);
	void stop();
	void InitHardware();

};

#endif  // Arm_H
