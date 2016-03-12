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
	   SmartDashboard::PutNumber("DRIVE DSD Encoder Initial",Robot::drive->Encoders()); //DSD is drive set distance
	   targetEncoderCounts = encoderCountsPerRotation * rotations + abs (Robot::drive->Encoders());

	   power = 0.0;
}



// Called repeatedly when this Command is scheduled to run
void DriveSetDistance::Execute()
{
	if(!IsFinished()){
    currentEncCountLeft = abs(Robot::drive ->Encoders());

    EncErrorLeft = targetEncoderCounts - currentEncCountLeft;
	SmartDashboard::PutNumber("DRIVE DSD encoder target: " ,targetEncoderCounts);
	SmartDashboard::PutNumber("DRIVE DSD encoder current :" ,currentEncCountLeft);
	SmartDashboard::PutNumber("DRIVE DSD motor power :" , power);
	SmartDashboard::PutNumber("DRIVE DSD encoder error :", EncErrorLeft);


	power = (EncErrorLeft * gain); // motors were going in the wrong direction

	if (power > 0.6) {

		power = 0.6;

	} else if (power < -0.6){

		power = -0.6;

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
