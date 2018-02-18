#ifndef SendData_H
#define SendData_H

#include "../CommandBase.h"

class SendData : public CommandBase {
public:
	SendData(double seconds);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

};

#endif  // SendData_H
