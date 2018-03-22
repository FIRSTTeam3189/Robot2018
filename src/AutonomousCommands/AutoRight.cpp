#include <AutonomousCommands/AutoRight.h>
#include <iostream>
#include <DriverStation.h>
#include "Constants.h"
#include "Commands/TRexArmGotoPosition.h"
#include "Commands/ClawOuttake.h"
#include "AutonomousCommands/GoForwardWithEncoders.h"
#include "AutonomousCommands/AutoEncoderTurn.h"
AutoRight::AutoRight() {

	std::string state = DriverStation::GetInstance().GetGameSpecificMessage();

		if(state[0] == 'L'){
			AddSequential(new GoForwardWithEncoders(102.5));
			AddSequential(new TRexArmGotoPosition(TREX_ARM_HIGH));
			AddSequential(new ClawOuttake());


		}else{
			AddSequential(new GoForwardWithEncoders(24));
			AddSequential(new AutoEncoderTurn(-16));
			AddSequential(new GoForwardWithEncoders(40));
			AddSequential(new AutoEncoderTurn(16));
			AddSequential(new GoForwardWithEncoders(221.5));
			AddSequential(new AutoEncoderTurn(16));
			AddSequential(new GoForwardWithEncoders(126));
			AddSequential(new AutoEncoderTurn(16));
			AddSequential(new GoForwardWithEncoders(12));		}
			AddSequential(new TRexArmGotoPosition(TREX_ARM_HIGH));
			AddSequential(new ClawOuttake());
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.
}
