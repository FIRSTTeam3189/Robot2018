#include <AutonomousCommands/Autonomous.h>
#include <iostream>
#include <DriverStation.h>

Autonomous::Autonomous() :
		frc::CommandGroup("Autonomous") {

	// the data is three chars defining side of objects from you perspective
	// (L = Left, R = Right, CAPS ARE IMPORTANT) Going closest to farthest
	// ex: "LLR" our switch is first being left from our driverstaion
	std::string state = DriverStation::GetInstance().GetGameSpecificMessage();

	if(state[0] == 'L'){

	}else{

	}

}
