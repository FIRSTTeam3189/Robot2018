#include <AutonomousCommands/AutoCenter.h>
#include <iostream>
#include <DriverStation.h>
#include "GoForwardWithEncoders.h"
#include "AutoEncoderTurn.h"
#include "Commands/TRexArmGotoPosition.h"
#include "Commands/ClawOuttake.h"
#include "Constants.h"
AutoCenter::AutoCenter() {
	std::string state = DriverStation::GetInstance().GetGameSpecificMessage();
	int side = state[0] = 'L' ? -1 :1;

	AddSequential(new GoForwardWithEncoders(12));
	AddSequential(new AutoEncoderTurn(17.7*side));
	AddSequential(new GoForwardWithEncoders(90));
	AddSequential(new AutoEncoderTurn(-17.7*side));
	AddSequential(new GoForwardWithEncoders(90.5));
	AddSequential(new TRexArmGotoPosition(TREX_ARM_HIGH));
	AddSequential(new ClawOuttake());
	AddSequential(new GoForwardWithEncoders(-1));

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