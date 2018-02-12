#include "Vision.h"
#include "../RobotMap.h"
#include "Constants.h"
#include "SmartDashboard/SmartDashboard.h"

#define BUFFER_SIZE 32

Vision::Vision() : frc::Subsystem("Vision") {
	uart = new frc::SerialPort(115200, frc::SerialPort::Port::kMXP);
}

void Vision::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void Vision::Ping() {
	std::string data = "Hello World.";
	unsigned int data_sent = uart->Write(data.c_str());

	if(data_sent != data.size()) {
		frc::SmartDashboard::PutString("Error", "Did not send full data over UART.");
		return;
	}

	char buffer[BUFFER_SIZE];
	uart->Read(buffer, BUFFER_SIZE);
	frc::SmartDashboard::PutString("Pong", buffer);

}
