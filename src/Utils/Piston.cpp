/*
 * Piston.cpp
 *
 *  Created on: Jan 9, 2018
 *      Author: scroo
 */

#include "Piston.h"

PistonDouble::PistonDouble(int extendID, int retractID, bool extended) {
	this->extended = new Solenoid(extendID);
	this->retracted = new Solenoid(retractID);
	this->extended->Set(extended);
	this->retracted->Set(!extended);
}

void PistonDouble::Extend() {
	extended->Set(true);
	retracted->Set(false);
}

void PistonDouble::Retract() {
	extended->Set(false);
	retracted->Set(true);
}

void PistonDouble::Toggle() {
	extended->Set(!extended->Get());
	retracted->Set(!extended->Get());

}

PistonSingle::PistonSingle(int extendID, bool extended) {
	this->extended = new Solenoid(extendID);
	this->extended->Set(extended);
}

void PistonSingle::Extend() {
	extended->Set(true);
}

void PistonSingle::Retract() {
	extended->Set(false);
}

void PistonSingle::Toggle() {
	extended->Set(!extended->Get());

}



