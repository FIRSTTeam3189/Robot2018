#ifndef DriveTrain_H
#define DriveTrain_H

#include <AnalogGyro.h>
#include <AnalogInput.h>
#include <AnalogPotentiometer.h>
#include <Commands/Subsystem.h>
#include <Encoder.h>
#include <RobotDrive.h>
#include <ctre/phoenix/MotorControl/CAN/TalonSRX.h>
#include <ctre/phoenix/MotorControl/ControlMode.h>
#include "RobotMap.h"
#include "Utils/Piston.h"


using CANTalon = ctre::phoenix::motorcontrol::can::TalonSRX;
using ControlMode = ctre::phoenix::motorcontrol::ControlMode;

/**
 * The DriveTrain subsystem incorporates the sensors and actuators attached to
 * the robots chassis. These include four drive motors, a left and right encoder
 * and a gyro.
 */
class Drivetrain: public frc::Subsystem {
public:
	Drivetrain();

	/**
	 * When no other command is running let the operator drive around
	 * using the PS3 joystick.
	 */
	void InitDefaultCommand() override;

	/**
	 * The log method puts interesting information to the SmartDashboard.
	 */
	void Log();
	/**
	 *straight drive for drivetrain
	 *@param power to run all motors at for the drivetrain
	 */
	void Drive(double power);

	/**
	 * Tank style driving for the DriveTrain.
	 * @param left Speed in range [-1,1]
	 * @param right Speed in range [-1,1]
	 */
	void Drive(double left, double right);
	//TODO document your code please
	void EngageWinch();

	void EngageDrivetrain();
	/**
	 * Stops all motors
	 */
	void Stop();

	/**
	 * returns the gyro stuff
	 */
	double GetHeading();

	/**
	 * Reset the robots sensors to the zero states.
	 */
	void Reset();

	/**
	 * @return The distance driven (average of left and right encoders).
	 */
	double GetDistance();

	/**
	 * @return The distance to the obstacle detected by the rangefinder.
	 */
	double GetDistanceToObstacle();

	void InitHardware();
private:
	CANTalon* frontLeft;
	CANTalon* rearLeft;
	CANTalon* frontRight;
	CANTalon* rearRight;
	Piston* winchPiston;

	//frc::Encoder rightEncoder { 3, 4 };
	//frc::AnalogInput rangefinder { 6 };
	//frc::AnalogGyro gyro { 1 };
};

#endif  // DriveTrain_H
