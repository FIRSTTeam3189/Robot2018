#ifndef Arm_H
#define Arm_H

#include <Commands/Subsystem.h>
#include <ctre/phoenix/MotorControl/CAN/TalonSRX.h>
#include <ctre/phoenix/MotorControl/ControlMode.h>
#include <AnalogPotentiometer.h>

using CANTalon = ctre::phoenix::motorcontrol::can::TalonSRX;
using ControlMode = ctre::phoenix::motorcontrol::ControlMode;
using Pot = AnalogPotentiometer;

class Arm : public frc::Subsystem {
private:

	CANTalon* shoulderMotor;
	CANTalon* elbowMotor;
	CANTalon* wristMotor;
	Pot* wristPot;
	Pot* elbowPot;
	Pot* shoulderPot;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	// It's desirable for you to kill yourself


public:
	Arm();
	/**
	 *
	 */
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

	void ControlWrist(double power);
	double GetShoulderPot();
	/**
	 * gets the value for the potentiometer on the elbow motor
	 * @returns value from 0 to 1023
	 */

	double GetWristPot();
	double GetElbowPot();
	/**
	 * get
	 * finds percent of the total span from 0-1 then finds the potentiometer value for the given angle value
	 * @param angle in radians of angle value
	 * kill me
	 * @return the equivalent potentiometer value for the given angle value
	 */
	double ShoulderToPot(double angle);
	double ElbowToPot(double angle);
	void InitHardware();

};

#endif  // Arm_H
