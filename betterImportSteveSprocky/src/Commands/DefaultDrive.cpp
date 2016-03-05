// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "DefaultDrive.h"

DefaultDrive::DefaultDrive() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::drive);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

// Called just before this Command runs the first time
void DefaultDrive::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void DefaultDrive::Execute() {
	float leftDrive = Robot::oi->getdriveStick()->GetRawAxis(1);
	float rightDrive = Robot::oi->getdriveStick()->GetRawAxis(3);
	leftDrive = leftDrive*2/3;
	rightDrive = rightDrive*2/3;
	Robot::drive->TwoAxis(leftDrive, rightDrive);
}

// Make this return true when this Command no longer needs to run execute()
bool DefaultDrive::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DefaultDrive::End() {
	Interrupted();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DefaultDrive::Interrupted() {
	Robot::drive->TwoAxis(0, 0);
}
