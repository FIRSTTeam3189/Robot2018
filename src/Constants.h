/*
 * Constants.h
 *
 *  Created on: Jan 14, 2018
 *      Author: Nathaniel Mansfield
 */

#ifndef SRC_CONSTANTS_H_
#define SRC_CONSTANTS_H_
// AUTONOMOUS VARIABLES
constexpr double FORWARD_TIME  = 5;
constexpr double FORWARD_POWER = .5;
//70.7
constexpr int SHOULDER_POT_MAX = 984;
constexpr int SHOULDER_POT_MIN = 0;
constexpr int SHOULDER_POT_RANGE = 15;//------------------------
constexpr int ELBOW_POT_MAX = 991;
constexpr int ELBOW_POT_MIN = 0;
constexpr int WRIST_POT_MIN = 0;
constexpr int WRIST_POT_MAX = 0;

constexpr int TREX_ARM_START = 633;
constexpr int TREX_ARM_HIGH = 618;
constexpr int TREX_ARM_MIDDLE = 603;
constexpr int TREX_ARM_LOW = 595;

constexpr double SHOULDER_ANGLE_MIN = 0;
constexpr double SHOULDER_ANGLE_MAX = 0;
constexpr double ELBOW_ANGLE_MIN = 0;
constexpr double ELBOW_ANGLE_MAX = 0;

constexpr double ARM_ONE_LENGTH = 40;
constexpr double ARM_TWO_LENGTH = 40;
constexpr double ARM_THREE_LENGTH = 10;
constexpr double phi = 0; // It can be 0 to pi/2 (90)
constexpr double ARM_POSITION_TOLERANCE = 3;
constexpr double ARM_SHOULDER_SPEED = 0.1;
constexpr double ARM_EBLOW_START_AT_ZERO_SPEED = 0;

//----------------------------------------------------------------------
constexpr double POT_RANGE = 1000;
constexpr double VOLTAGE_LOW = 4.733886234;
constexpr double VOLTAGE_HIGH = 4.893798327;
constexpr double VOLTAGE_RANGE = VOLTAGE_HIGH - VOLTAGE_LOW;


constexpr double ARM_ANGLE_RANGE = 0.052;
constexpr double ARM_SWITCH = 15;

constexpr double CLAW_INTAKE_POWER = 0.275;
constexpr double CLAW_OUTAKE_POWER = -0.75;

constexpr double WHEEL_CIRCUMFERENCE= 0;
constexpr int SIGNALS_PER_REVOLUTION = 2;

constexpr double AUTO_SPEED = 0.5;

#endif /* SRC_CONSTANTS_H_ */
