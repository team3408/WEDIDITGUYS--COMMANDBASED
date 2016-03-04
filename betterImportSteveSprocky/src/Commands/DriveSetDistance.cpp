#include "DriveSetDistance.h"

#include "Commands/Subsystem.h"
#include "../Robot.h"
#include <cmath>

DriveSetDistance::DriveSetDistance(double Distance)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::drive);

			targetDistance = Distance;


		   overshootNumber = 10;
}

// Called just before this Command runs the first time
void DriveSetDistance::Initialize()
{
	   float rotations = targetDistance / circumference;
	   SmartDashboard::PutNumber("InitialEncoderCounts",Robot::drive->Encoders());
	   targetEncoderCounts = encoderCountsPerRotation * rotations +  Robot::drive->Encoders();
}



// Called repeatedly when this Command is scheduled to run
void DriveSetDistance::Execute()
{
	if(!IsFinished()){
    currentEncCountLeft = Robot::drive ->Encoders();

    EncErrorLeft = targetEncoderCounts - currentEncCountLeft;
	SmartDashboard::PutNumber("target encoder counts:" ,targetEncoderCounts);


	power = - (EncErrorLeft * gain); // motors were going in the wrong direction

	if (power > 1) {

		power = 1;

	} else if (power < -1){

		power = -1;

	}

	left = power;
	right = power;

	Robot::drive -> TwoAxis(left, right);
    }
	
}

// Make this return true when this Command no longer needs to run execute()
bool DriveSetDistance::IsFinished()
{
	return (currentEncCountLeft > targetEncoderCounts - overshootNumber && currentEncCountLeft < targetEncoderCounts + overshootNumber);
}

// Called once after isFinished returns true
void DriveSetDistance::End()
{
	Execute();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveSetDistance::Interrupted()
{
	Execute();
}
