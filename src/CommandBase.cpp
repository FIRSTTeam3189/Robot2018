#include "CommandBase.h"

#include <Commands/Scheduler.h>

std::unique_ptr<OI> CommandBase::oi = std::make_unique<OI>();
std::unique_ptr<Drivetrain> CommandBase::drivetrain = std::make_unique<Drivetrain>();


CommandBase::CommandBase(const std::string &name) :
		frc::Command(name) {

}
