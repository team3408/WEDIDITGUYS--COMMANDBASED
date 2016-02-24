#include "DriveSetDistance.h"

#include "Commands/Subsystem.h"
#include "../Robot.h"
#include <cmath>

DriveSetDistance::DriveSetDistance(double Distance)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::drive);
}

// Called just before this Command runs the first time
void DriveSetDistance::Initialize()
{


}

	float midPower = 0.66;
   float leftPower;
   float rightPower;
   float currentDistance;
   int currentEncCountLeft;
   int currentEncCountRight;

   int overshootNumber = 100;


   float targetDistance;
   const float encoderCountsPerRotation = 360;
   const float diameter = 7.6;						// 7.6 inches is the diameter of our robot
   const float circumference = diameter * 3.14159;
   float rotations = targetDistance / circumference;
   float EncErrorLeft;
   int initialEncCountLeft = Robot::drive->Encoders();
   float targetEncoderCounts = encoderCountsPerRotation * rotations + initialEncCountLeft;
   float left;
   float right;
	 double gain = 0.01;

// Called repeatedly when this Command is scheduled to run
void DriveSetDistance::Execute()
{

    currentEncCountLeft = Robot::drive ->Encoders();

    EncErrorLeft = targetEncoderCounts - currentEncCountLeft;


	power = midPower + (EncErrorLeft * gain);

	if (power > 1) {

		power = 1;

	} else if (power < -1){

		power = -1;

	}

	left = power;
	right = power;

	Robot::drive -> TwoAxis(left, right);
	
}

// Make this return true when this Command no longer needs to run execute()
bool DriveSetDistance::IsFinished()
{
	return (currentEncCountLeft > targetEncoderCounts - overshootNumber && currentEncCountLeft < targetEncoderCounts + overshootNumber);
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
