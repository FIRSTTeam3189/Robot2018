#ifndef Wrist_H
#define Wrist_H

#include <Commands/Subsystem.h>
#include <Commands/Subsystem.h>
#include <ctre/phoenix/MotorControl/CAN/TalonSRX.h>
#include <ctre/phoenix/MotorControl/ControlMode.h>
#include <SmartDashboard/SmartDashboard.h>
#include <AnalogPotentiometer.h>
#include "RobotMap.h"

using CANTalon = ctre::phoenix::motorcontrol::can::TalonSRX;
using ControlMode = ctre::phoenix::motorcontrol::ControlMode;
using Pot = AnalogPotentiometer;

class Wrist : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	CANTalon* wristMotor;
	Pot* wristPot;

public:
	Wrist();//TODO docs?
	void ControlWrist(double power);
	double GetWristPot();
	void InitDefaultCommand();
	void InitHardware();
};

#endif  // Wrist_H
