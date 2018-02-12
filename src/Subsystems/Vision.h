#ifndef Vision_H
#define Vision_H

#include <Commands/Subsystem.h>
#include <SerialPort.h>

class Vision : public frc::Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	frc::SerialPort* uart;

public:
	Vision();
	void InitDefaultCommand();
	void Ping();
};

#endif  // Vision_H
