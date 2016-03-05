#include "FastFlatLoader.h"

FastFlatLoader::FastFlatLoader()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::loaderAngle);
}

// Called just before this Command runs the first time
void FastFlatLoader::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void FastFlatLoader::Execute()
{
	Robot::loaderAngle->Move(Robot::oi->getbuttonStick()->GetRawAxis(1));
}

// Make this return true when this Command no longer needs to run execute()
bool FastFlatLoader::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void FastFlatLoader::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void FastFlatLoader::Interrupted()
{

}
