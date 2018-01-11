/*
 * Piston.cpp
 *
 *  Created on: Jan 9, 2018
 *      Author: scroo
 */

#include "Piston.h"

Piston::Piston(int extendID, int retractID, bool extended) {
	this->extended = new Solenoid(extendID);
	this->retracted = new Solenoid(retractID);
	this->extended->Set(extended);
	this->retracted->Set(!extented);
}

 void Piston::Extend() {
	 extended->Set(true);
	 retracted->Set(false);
 }

void Piston::Retract(){
	extended->Set(false);
	retracted->Set(true);
}

void Piston::Toggle(){
	extended->Set(!extended->Get());
	retracted->Set(!extended->Get());

}
