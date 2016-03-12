#include "AutoWithTime.h"

AutoWithTime::AutoWithTime()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);

	SetTimeout(5);

}

// Called just before this Command runs the first time
void AutoWithTime::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void AutoWithTime::Execute()
{

	Robot::drive -> TwoAxis(.25, .25);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoWithTime::IsFinished()
{
	return IsTimedOut();
}

// Called once after isFinished returns true
void AutoWithTime::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoWithTime::Interrupted()
{

}
