#ifndef TankDriveWithLimit_H
#define TankDriveWithLimit_H

#include "../CommandBase.h"

class TankDriveWithLimit: public CommandBase {
public:
	TankDriveWithLimit();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // TankDriveWithLimit_H
