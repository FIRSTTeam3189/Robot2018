#ifndef PingVision_H
#define PingVision_H

#include "../CommandBase.h"

class PingVision : public CommandBase {
public:
	PingVision();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // PingVision_H
