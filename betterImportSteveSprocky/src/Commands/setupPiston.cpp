#include "setupPiston.h"

setupPiston::setupPiston()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::climberPneumatics);
	SetTimeout(.1);
}

// Called just before this Command runs the first time
void setupPiston::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void setupPiston::Execute()
{
	Robot::climberPneumatics->LowAir();
}

// Make this return true when this Command no longer needs to run execute()
bool setupPiston::IsFinished()
{

	return IsTimedOut();
}

// Called once after isFinished returns true
void setupPiston::End()
{
	Robot::climberPneumatics->Off();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void setupPiston::Interrupted()
{
	End();
}
