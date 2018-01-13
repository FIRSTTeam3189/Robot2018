#ifndef Arm_H
#define Arm_H

#include <Commands/Subsystem.h>
#include <ctre/phoenix/MotorControl/CAN/TalonSRX.h>
#include <ctre/phoenix/MotorControl/ControlMode.h>

using CANTalon = ctre::phoenix::motorcontrol::can::TalonSRX;
using ControlMode = ctre::phoenix::motorcontrol::ControlMode;

class Arm : public frc::Subsystem {
private:

	CANTalon* motor;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

public:
	Arm();
	void InitDefaultCommand();
	void ControlArm(double power);
	void InitHardware();

};

#endif  // Arm_H
