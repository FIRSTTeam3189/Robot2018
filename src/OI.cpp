#include <Commands/MoveForward.h>
#include <Commands/ReceiveData.h>
#include <Commands/SendData.h>
#include "OI.h"
#include "Commands/ArmGoToPoint.h"

#include <SmartDashboard/SmartDashboard.h>

#include "Commands/Autonomous.h"
#include "Commands/ClawIntake.h"
#include "Commands/ClawOuttake.h"

OI::OI() {

	copilot_2 = new JoystickButton(&copilot, 2);
	copilot_3 = new JoystickButton(&copilot, 3);
	leftTrigger = new JoystickButton(&left, 1);
	leftTwo = new JoystickButton(&left, 2);
	leftTwo->WhileHeld(new MoveForwardWhileHeld());
	moveArm = new JoystickButton(&left, 3);
	intake = new JoystickButton(&copilot, 4);
	outtake = new JoystickButton(&copilot, 5);
	receiveData = new JoystickButton(&copilot, 10);
	sendData = new JoystickButton(&copilot, 11);

	intake->WhileHeld(new ClawIntake());
	outtake->WhileHeld(new ClawOuttake());

	receiveData->WhenPressed(new ReceiveData());
	//mAgIc NuMb3Rs
	sendData->WhenPressed(new SendData(0.1));
}

double OI::GetLeftY() {
	return left.GetY(frc::GenericHID::JoystickHand::kLeftHand);
}

double OI::GetRightY() {
	return right.GetY(frc::GenericHID::JoystickHand::kRightHand);
}

double OI::GetCoPilotY() {
	return copilot.GetY(frc::GenericHID::JoystickHand::kRightHand)
			+ copilot.GetY(frc::GenericHID::JoystickHand::kLeftHand);

}

void OI::CheckMath() {
	moveArm->WhenPressed(new ArmGoToPoint(15, 50));
}


