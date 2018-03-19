#ifndef ROBOTMAP_H
#define ROBOTMAP_H

//Motors
constexpr int LEFT_CLAW_MOTOR = 0;
constexpr int RIGHT_CLAW_MOTOR = 1;

constexpr int DRIVE_RIGHT_FRONT = 6;
constexpr int DRIVE_RIGHT_BACK = 5;
constexpr int DRIVE_LEFT_FRONT = 1;
constexpr int DRIVE_LEFT_BACK = 2;

constexpr int ARM_SHOULDER_MOTOR = 3;
constexpr int ARM_SHOULDER_MOTOR_2 = 4;
constexpr int ARM_ELBOW_MOTOR = 7;
constexpr int ARM_WRIST_MOTOR = 8;

//Pistons
constexpr int DRIVETRAIN_GEARBOX_EXTEND = 2;
constexpr int DRIVETRAIN_GEARBOX_RETRACT = 3;
//for presentation
constexpr int PISTON_EXTEND = 0;//up
constexpr int PISTON_RETRACT = 1;//down

constexpr int CLAW_EXTEND = 4;//closed
constexpr int CLAW_RETRACT = 5;//open

constexpr int ELBOW_BRAKE_PISTON_EXTEND = 6;
constexpr int ELBOW_BRAKE_PISTON_RETRACT = 7;
constexpr int SHOULDER_BRAKE_PISTON_EXTEND = 8;
constexpr int SHOULDER_BRAKE_PISTON_RETRACT = 9;

//inputs
constexpr int LIMIT_SWITCH = 0;

constexpr int ELBOW_POT = 0;
constexpr int SHOULDER_POT = 1;
constexpr int WRIST_POT = 2;

constexpr int RIGHT_ENCODER1 = 3;
constexpr int RIGHT_ENCODER2 = 4;
constexpr int LEFT_ENCODER1 = 5;
constexpr int LEFT_ENCODER2 = 6;

#endif  // ROBOTMAP_H
