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
	Pot* elbowPot;
	Pot* shoulderPot;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities


public:
	Arm();
	/**
	 *
	 */
	void InitDefaultCommand();
	/**
	 *Put methods for controlling this subsystem
	 *here. Call these from Commands.
	 */
	void ControlShoulder(double power);
	void ControlElbow(double power);
	double GetShoulderPot();
	double GetElbowPot();
	void InitHardware();

};

#endif  // Arm_H
