#ifndef ArmGoToPoint_H
#define ArmGoToPoint_H

#include "../CommandBase.h"
#include "Constants.h"

class ArmGoToPoint : public CommandBase {
public:
	ArmGoToPoint(double x, double y);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	double armAngle[2] {0,0};
};


#endif  // ArmGoToPoint_H
