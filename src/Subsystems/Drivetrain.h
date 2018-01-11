#ifndef Drivetrain_H
#define Drivetrain_H

#include <Commands/Subsystem.h>
#include <ctrlib/CANTalon.h>
#include "Commands/DrivetrainTankDrive.h"
#include <RobotMap.h>

class Drivetrain : public Subsystem {
private:
	CANTalon* RightMotor;
	CANTalon* LeftMotor;
	CANTalon* RightFollower;
	CANTalon* LeftFollower;
	CANTalon* RightFollower2;
	CANTalon* LeftFollower2;
public:
	Drivetrain();
	void InitDefaultCommand();
	void Drive(double right, double left);
	void InitHardware();

};

#endif  // Drivetrain_H
