/*
 * Piston.cpp
 *
 *  Created on: Jan 9, 2018
 *      Author: not dev
 */

#include "Piston.h"

PistonDouble::PistonDouble(int extendID, int retractID, int deviceID, bool extended) {
	this->extended = new Solenoid(deviceID, extendID);
	this->retracted = new Solenoid(deviceID, retractID);
	this->extended->Set(extended);
	this->retracted->Set(!extended);
}

PistonDouble::PistonDouble(PistonData init) {
	this->extended = new Solenoid(init.deviceID, init.extendID);
	this->retracted = new Solenoid(init.deviceID, init.retractID);
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

PistonSingle::PistonSingle(int extendID, int deviceID, bool extended) {
	this->extended = new Solenoid(deviceID, extendID);
	this->extended->Set(extended);
}

PistonSingle::PistonSingle(PistonData init) {
	this->extended = new Solenoid(init.deviceID, init.extendID);
	this->extended->Set(init.extendedByDefault);
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

PistonData::PistonData(int extendID_, int retractID_, int deviceID_, bool extended_ = false){
	extendID = extendID_;
	retractID = retractID_;
	deviceID = deviceID_;
	extendedByDefault = extended_;
}

