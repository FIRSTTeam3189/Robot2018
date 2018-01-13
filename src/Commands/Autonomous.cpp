#include "Autonomous.h"

#include <iostream>
#include <DriverStation.h>

Autonomous::Autonomous() :
		frc::CommandGroup("Autonomous") {

	std::string state = DriverStation::GetInstance().GetGameSpecificMessage();

	if(state[0] == 'L'){

	}else{

	}

}
