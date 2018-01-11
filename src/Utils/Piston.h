/*
 * Piston.h
 *
 *  Created on: Jan 9, 2018
 *      Author: Everybody
 */

#ifndef PISTON_H_
#define PISTON_H_

#include <WPILib.h>
#include <Solenoid.h>

class Piston {
private:
	Solenoid* extended;
	Solenoid* retracted;
public:
	/**
	 * Provides interface for Pistons
	 * @param extendID Device ID for extended solenoid
	 * @param retractID Device ID for retracted solenoid
	 * @param extended the default state of the piston
	 */
	Piston(int extendID, int retractID, bool extended = false);

	/**
	 * Channels air into The extension of piston.
	 */
	void Extend();

	/**
	 * Channels air into the Retraction of piston
	 */
	void Retract();

	/**
	 * Toggles the state of the piston.f
	 */
	void Toggle();
};

#endif /* PISTON_H_ */
