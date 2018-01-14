#include "OI.h"

#include <SmartDashboard/SmartDashboard.h>

#include "Commands/Autonomous.h"

#include "Commands/ClawToggle.h"

OI::OI() {
	copilot_2 = new JoystickButton(&copilot, 2);
	copilot_3 = new JoystickButton(&copilot, 3);
	leftTrigger = new JoystickButton(&left, 1);

	leftTrigger->WhenPressed(new ClawToggle());
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
