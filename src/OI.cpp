#include "OI.h"

#include <SmartDashboard/SmartDashboard.h>

#include "Commands/Autonomous.h"

OI::OI() {

}

double OI::GetLeftY(){
	return LeftJoi.GetY();
}

double OI::GetRightY(){
	return RightJoi.GetY();
}
