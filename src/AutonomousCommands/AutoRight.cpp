#include <AutonomousCommands/AutoRight.h>
#include <iostream>
#include <DriverStation.h>
#include "Constants.h"
#include "Commands/TRexArmGotoPosition.h"
#include "Commands/ClawOuttake.h"
#include "AutonomousCommands/GoForwardWithEncoders.h"
#include "AutonomousCommands/AutoEncoderTurn.h"
#include "DriveEncoders.h"
AutoRight::AutoRight() {

	std::string state = DriverStation::GetInstance().GetGameSpecificMessage();
	if(state[0] == 'R'){
		AddSequential(new DriveEncoders(AUTO_SPEED,Forward,102.5));
		AddParallel(new TRexArmGotoPosition(TREX_ARM_HIGH));
		AddSequential(new ClawOuttake());


	}else{

		AddSequential(new DriveEncoders(AUTO_SPEED,Forward,24));
		AddSequential(new DriveEncoders(AUTO_SPEED,Right,17.7));
		AddSequential(new DriveEncoders(AUTO_SPEED,Forward,40));
		AddSequential(new DriveEncoders(AUTO_SPEED,Left,17.7));
		AddSequential(new DriveEncoders(AUTO_SPEED,Forward,221.5));
		AddSequential(new DriveEncoders(AUTO_SPEED,Left,17.7));
		AddSequential(new DriveEncoders(AUTO_SPEED,Forward,126));
		AddSequential(new DriveEncoders(AUTO_SPEED,Left,17.7));
		AddSequential(new DriveEncoders(AUTO_SPEED,Forward,12));
		AddParallel(new TRexArmGotoPosition(TREX_ARM_HIGH));
		AddSequential(new ClawOuttake());
	}
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
