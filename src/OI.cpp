#include "OI.h"

#include <SmartDashboard/SmartDashboard.h>

#include <AutonomousCommands/Autonomous.h>
#include "Commands/ClawIntake.h"
#include "Commands/ClawOuttake.h"
#include "Commands/ClawOpen.h"
#include "Commands/ClawClose.h"
#include "Commands/WristLift.h"
#include "Commands/WristLower.h"
#include "Commands/ArmGoToPoint.h"
#include "Commands/JoystickArmControl.h"
#include "Commands/TankDriveWithJoystick.h"
#include <Commands/MoveForward.h>
#include "Commands/TRexArmGotoPosition.h"
#include "Commands/TRexArmGotoPositionLock.h"
#include "Commands/ClawIntakeClosed.h"
#include "Commands/WristJoystickControl.h"
#include "Constants.h"

OI::OI() {

}

double OI::GetLeftY() {
	return left.GetY(frc::GenericHID::JoystickHand::kLeftHand);
}

double OI::GetRightY() {
	return right.GetY(frc::GenericHID::JoystickHand::kRightHand);
}

double OI::GetCoPilotY() {
	return copilot.GetY(frc::GenericHID::JoystickHand::kRightHand);

}



void OI::InitilizeOI(){
	copilot_2 = new JoystickButton(&copilot, 2);
	copilot_3 = new JoystickButton(&copilot, 3);
	copilot_1 = new JoystickButton(&copilot, 1);
	copilot_4 = new JoystickButton(&copilot, 4);
	copilot_5 = new JoystickButton(&copilot, 5);
	copilot_6 = new JoystickButton(&copilot, 6);
	copilot_7 = new JoystickButton(&copilot, 7);
	copilot_8 = new JoystickButton(&copilot, 8);
	copilot_9 = new JoystickButton(&copilot, 9);
	copilot_10 = new JoystickButton(&copilot, 10);
	copilot_11 = new JoystickButton(&copilot, 11);
	right_1 = new JoystickButton(&right, 1);
	right_8 = new JoystickButton(&right, 8);
	right_9 = new JoystickButton(&right, 9);

	copilot_3->WhileHeld(new ClawIntake());
	copilot_2->WhileHeld(new ClawIntakeClosed());
	copilot_1->WhileHeld(new ClawOuttake());

	//copilot_6->WhenPressed(new ClawOpen());
	//copilot_11->WhenPressed(new ClawClose());
	copilot_11->WhileHeld(new WinchJoystickControl());
	//copilot_6->WhileHeld(new JoystickArmControl());

	copilot_7->WhenPressed(new TRexArmGotoPosition(TREX_ARM_LOW));
	copilot_8->WhenPressed(new TRexArmGotoPosition(TREX_ARM_MIDDLE));
	copilot_9->WhenPressed(new TRexArmGotoPositionLock(TREX_ARM_HIGH));
	copilot_10->WhenPressed(new TRexArmGotoPosition(TREX_ARM_START));
	//copilot_4->WhenPressed(new JoystickArmControl());

}
bool OI::GetRight1Button(){
return	right_1->Get();
}

void OI::CheckMath() {
	moveArm->WhenPressed(new ArmGoToPoint(15, 50));
}

