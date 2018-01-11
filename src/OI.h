#ifndef OI_H_
#define OI_H_

#include <Buttons/JoystickButton.h>
#include <Joystick.h>

class OI {
public:
	OI();
	double GetLeftY();
	double GetRightY();


private:
	Joystick LeftJoi{0};
	Joystick RightJoi{1};
};
#endif  // OI_H_
