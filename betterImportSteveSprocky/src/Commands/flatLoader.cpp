// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "flatLoader.h"
#include "../RobotMap.h"
#include "WPILib.h"

flatLoader::flatLoader() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::loaderAngle);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

// Called just before this Command runs the first time
void flatLoader::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
const int gain = 0.008;//These are constant so that they compile better
const int targetAngle = 5;
void flatLoader::Execute() {

	int currentAngle = Robot::loaderAngle->GetAngle();//angle is returned in degrees
	int angleError = currentAngle - targetAngle;
	float angleAdjustment = angleError * gain;
	
	double power = angleAdjustment;
	
	if (power > 1) {
		power = 1;
	} 
	
	Robot::loaderAngle->Move(power);
	
}

// Make this return true when this Command no longer needs to run execute()
bool flatLoader::IsFinished() {
	if GetAngle() <= 5 {
		return true;
	} else if GetAngle() >= 5 {
		return false;
	}
}

// Called once after isFinished returns true
void flatLoader::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void flatLoader::Interrupted() {

}
