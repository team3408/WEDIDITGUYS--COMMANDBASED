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

	SmartDashboard::PutNumber("LOADER initial flat loader angle:", Robot::loaderAngle->GetAngle());
	SmartDashboard::PutNumber("LOADER initial power:", power);
	currentAngle = Robot::loaderAngle->GetAngle();
	previousAngle = Robot::loaderAngle->GetAngle();
	//power = 0;
	// Called repeatedly when this Command is scheduled to run
	gain;//These are constant so that they compile better
	targetAngle;

}

void flatLoader::Execute() {
	this->previousAngle = currentAngle;
	this->currentAngle = Robot::loaderAngle->GetAngle();//angle is returned in degrees
	int angleError = currentAngle - targetAngle;// produces positive values
	float angleAdjustment = angleError * gain;

	power = angleAdjustment;

	if (power > 0.3) {
		power = 0.3;
	}

	Robot::loaderAngle->Move(power);

	SmartDashboard::PutNumber("LOADER current flat loader angle:", Robot::loaderAngle->GetAngle());
	SmartDashboard::PutNumber("LOADER current power:", power);
	SmartDashboard::PutNumber("LOADER current angleAdjustment:", angleAdjustment);
	SmartDashboard::PutNumber("LOADER current angleError:", angleError);


}

// Make this return true when this Command no longer needs to run execute()
bool flatLoader::IsFinished() {
	SmartDashboard::PutNumber("LOADER previousAngle", previousAngle);
	return ((previousAngle <= overshootNumber + targetAngle) && (previousAngle >= targetAngle - overshootNumber) );

}

// Called once after isFinished returns true
void flatLoader::End() {
	Robot::loaderAngle->Move(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void flatLoader::Interrupted() {
	End();
}
