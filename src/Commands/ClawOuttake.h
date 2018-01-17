#ifndef ClawOuttake_H
#define ClawOuttake_H

#include "../CommandBase.h"

class ClawOuttake : public CommandBase {
public:
	ClawOuttake();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ClawOuttake_H
