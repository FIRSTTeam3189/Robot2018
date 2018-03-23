#ifndef AutoForwardTime_H
#define AutoForwardTime_H

#include "../CommandBase.h"

class AutoForwardTime : public CommandBase {
public:
	AutoForwardTime(double seconds, double power_);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	double seconds;
	double power;
};

#endif  // AutoForwardTime_H
