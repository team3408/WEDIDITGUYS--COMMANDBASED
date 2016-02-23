#include "SetupPiston.h"

SetupPiston::SetupPiston()
{
	Requires(Robot::climberPneumatics);
	SetTimeout(.3);
	//s() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void SetupPiston::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void SetupPiston::Execute()
{
	Robot::climberPneumatics->LowAir();
}

// Make this return true when this Command no longer needs to run execute()
bool SetupPiston::IsFinished()
{
	return IsTimedOut();
}

// Called once after isFinished returns true
void SetupPiston::End()
{
	Robot::climberPneumatics->Off();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetupPiston::Interrupted()
{
	End();
}
