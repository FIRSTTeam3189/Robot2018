#ifndef OI_H_
#define OI_H_

#include <Buttons/JoystickButton.h>
#include <Joystick.h>

class OI {
public:
	OI();
	double GetLeftY();
	double GetRightY();
	double GetCoPilotY();

private:
	frc::Joystick left { 0 };
	frc::Joystick right { 1 };
	frc::Joystick copilot { 2 };

	frc::JoystickButton* copilot_2;
	frc::JoystickButton* copilot_3;

	frc::JoystickButton* leftTrigger;
};

#endif  // OI_H_
