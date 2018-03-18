#ifndef Pivot_H
#define Pivot_H

#include "../CommandBase.h"

class Pivot : public CommandBase {
public:
	Pivot();
	void Initialize(double radians);
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // Pivot_H
