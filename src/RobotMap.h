#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include <Utils/Piston.h>

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
constexpr int DRIVETRAIN_PISTON = PistonData(2, 3, 0, false);
//for presentation
constexpr int PISTON_PISTON = PistonData(0, 1, 0, false);

constexpr int CLAW_PISTON = PistonData(0, 7, 1, false);

constexpr int BRAKES_PISTON = PistonData(4, 5, 1, false);
//constexpr int SHOULDER_BRAKE_PISTON = PistonData(7, 8, 1, false);

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
