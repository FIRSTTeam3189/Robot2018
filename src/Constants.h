/*
 * Constants.h
 *
 *  Created on: Jan 14, 2018
 *      Author: Nathaniel Mansfield
 */

#ifndef SRC_CONSTANTS_H_
#define SRC_CONSTANTS_H_

constexpr int SHOULDER_POT_MAX = 0;
constexpr int SHOULDER_POT_MIN = 0;
constexpr int ELBOW_POT_MAX = 0;
constexpr int ELBOW_POT_MIN = 0;
constexpr int WRIST_POT_MIN = 0;
constexpr int WRIST_POT_MAX = 0;

constexpr double SHOULDER_ANGLE_MIN = 0;
constexpr double SHOULDER_ANGLE_MAX = 0;
constexpr double ELBOW_ANGLE_MIN = 0;
constexpr double ELBOW_ANGLE_MAX = 0;

constexpr double ARM_ONE_LENGTH = 40;
constexpr double ARM_TWO_LENGTH = 40;
constexpr double ARM_THREE_LENGTH = 10;
constexpr double phi = 0; // It can be 0 to pi/2 (90)


constexpr double ARM_ANGLE_RANGE = 0.052;
constexpr double ARM_SWITCH = 25;

constexpr double CLAW_INTAKE_POWER = 0.5;
constexpr double CLAW_OUTAKE_POWER = -0.5;

#endif /* SRC_CONSTANTS_H_ */
