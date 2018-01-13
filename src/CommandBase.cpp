#include "CommandBase.h"

#include <Commands/Scheduler.h>

std::unique_ptr<OI> CommandBase::oi = std::make_unique<OI>();
std::unique_ptr<Drivetrain> CommandBase::drivetrain = std::make_unique<
		Drivetrain>();
std::unique_ptr<Arm> CommandBase::arm = std::make_unique<Arm>();

CommandBase::CommandBase(const std::string &name) :
		frc::Command(name) {

}
-
