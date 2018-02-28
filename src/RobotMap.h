#ifndef ROBOTMAP_H
#define ROBOTMAP_H

constexpr int CLAW_EXTEND = 4;
constexpr int CLAW_RETRACT = 5;

constexpr int LEFT_CLAW_MOTOR = 3;
constexpr int RIGHT_CLAW_MOTOR = 4;

constexpr int DRIVE_RIGHT_FRONT = 6;
constexpr int DRIVE_RIGHT_BACK = 5;
constexpr int DRIVE_LEFT_FRONT = 1;
constexpr int DRIVE_LEFT_BACK = 2;

constexpr int ARM_SHOULDER_MOTOR = 7;
constexpr int ARM_ELBOW_MOTOR = 8;
constexpr int ARM_WRIST_MOTOR = 9;

constexpr int ELBOW_POT = 0;
constexpr int SHOULDER_POT = 1;
constexpr int WRIST_POT = 2;

constexpr int WRIST_PISTON_EXTEND = 0;
constexpr int WRIST_PISTON_RETRACT = 1;

constexpr int ELBOW_BRAKE_PISTON_EXTEND = 2;
constexpr int ELBOW_BRAKE_PISTON_RETRACT = 3;
constexpr int SHOULDER_BRAKE_PISTON_EXTEND = 2;
constexpr int SHOULDER_BRAKE_PISTON_RETRACT = 3;

constexpr int LIMIT_SWITCH = 0;

constexpr int GEARBOX_EXTEND = 1;
constexpr int GEARBOX_RETRACT = 2;
#endif  // ROBOTMAP_H
