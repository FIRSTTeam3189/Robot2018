#ifndef ClawToggle_H
#define ClawToggle_H

#include "../CommandBase.h"

class ClawToggle : public CommandBase {
public:
	ClawToggle();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ClawToggle_H
