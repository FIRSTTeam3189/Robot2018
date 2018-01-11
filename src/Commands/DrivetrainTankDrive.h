#ifndef DrivetrainTankDrive_H
#define DrivetrainTankDrive_H

#include "../CommandBase.h"

class DrivetrainTankDrive : public CommandBase {
public:
	DrivetrainTankDrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DrivetrainTankDrive_H
