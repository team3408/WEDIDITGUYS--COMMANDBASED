#include "DriveSetDistance.h"

#include "Commands/Subsystem.h"
#include "../Robot.h"

DriveSetDistance::DriveSetDistance()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::drive);
}

// Called just before this Command runs the first time
void DriveSetDistance::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void DriveSetDistance::Execute()
{
	Robot::drive -> TwoAxis(1, 2);

}

// Make this return true when this Command no longer needs to run execute()
bool DriveSetDistance::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void DriveSetDistance::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveSetDistance::Interrupted()
{

}
