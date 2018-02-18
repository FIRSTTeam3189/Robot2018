#ifndef ReceiveData_H
#define ReceiveData_H

#include "../CommandBase.h"

class ReceiveData : public CommandBase {
public:
	ReceiveData();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

};

#endif  // ReceiveData_H
