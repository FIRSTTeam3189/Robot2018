#include <SmartDashboard/SmartDashboard.h>
#include <Subsystems/Vision.h>
#include <string>

#define BUFFER_SIZE 128

Vision::Vision() : frc::Subsystem("Vision") {
}

void Vision::InitHardware() {
	uart = new frc::SerialPort(115200, frc::SerialPort::Port::kMXP);
	uart->SetTimeout(0.1);
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

void Vision::ReceiveData() {
	// Make a buffer and read in data.
	char buffer[BUFFER_SIZE];
	int data_read = uart->Read(buffer, BUFFER_SIZE);

	// Print data to smart dashboard.
	frc::SmartDashboard::PutNumber("Last Data Read Size", data_read);
	std::string current_string = frc::SmartDashboard::GetString("Serial Output", "");
	current_string.append(buffer);
	frc::SmartDashboard::PutString("Serial Output", current_string.c_str());
}

void Vision::SendData() {
	const std::string data = "taco is a good comment";
	uart->Write(data.c_str());									//taco
	uart->Flush();
}
