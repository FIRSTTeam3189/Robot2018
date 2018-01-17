#ifndef Claw_H
#define Claw_H

#include <Commands/Subsystem.h>
#include"Utils/Piston.h"
#include<ctre/phoenix/MotorControl/CAN/TalonSRX.h>

using CANTalon = ctre::phoenix::motorcontrol::can::TalonSRX;
using ControlMode = ctre::phoenix::motorcontrol::ControlMode;


class Claw : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	CANTalon* Left;
	CANTalon* Right;


public:
	Claw();
	void InitDefaultCommand();
	void SetPower(double power);
	void InitHardware();
};

#endif  // Claw_H
