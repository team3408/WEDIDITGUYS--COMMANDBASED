#include "LiftLoader.h"

LiftLoader::LiftLoader()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::loaderAngle);
	currentAngle = 0;

}

// Called just before this Command runs the first time
void LiftLoader::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
const int gain = 0.008;//These are constant so that they compile better
const int targetAngle = 5;

void LiftLoader::Execute()
{

	this->currentAngle = Robot::loaderAngle->GetAngle();//angle is returned in degrees
	int angleError = currentAngle - targetAngle;
	float angleAdjustment = angleError * gain;

	double power = angleAdjustment;

	if (power < -1) {
		power = -1;
	}

	Robot::loaderAngle->Move(power);

}

// Make this return true when this Command no longer needs to run execute()
bool LiftLoader::IsFinished()
{
	return (currentAngle <= 5);
}

// Called once after isFinished returns true
void LiftLoader::End()
{
	Robot::loaderAngle->Move(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LiftLoader::Interrupted()
{
	End();
}
