#ifndef ControlWinchwithJoystick_H
#define ControlWinchwithJoystick_H

#include "../CommandBase.h"

class ControlWinchwithJoystick : public CommandBase {
public:
	ControlWinchwithJoystick();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ControlWinchwithJoystick_H
