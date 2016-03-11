#include "LiftLoader.h"
#include "../RobotMap.h"
#include "WPILib.h"


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
	SmartDashboard::PutNumber("LOADER liftloader encoder angle :", Robot::loaderAngle->GetAngle());
	SmartDashboard::PutNumber("LOADER liftloader motor initial power :", power);
	currentAngle = Robot::loaderAngle->GetAngle();
	previousAngle = Robot::loaderAngle->GetAngle();
	gain;
	targetAngle;
}

void LiftLoader::Execute()
{
	this->previousAngle = currentAngle;
	this->currentAngle = Robot::loaderAngle->GetAngle();//angle is returned in degrees
	int angleError = currentAngle - targetAngle;
	float angleAdjustment = angleError * gain;

	power = angleAdjustment;

	if (power > 0.3) {
		power = 0.3;
	} else if (power < -0.3){
		power = -0.3;
	}

	Robot::loaderAngle->Move(power);

	SmartDashboard::PutNumber("LOADER flatloader encoder current angle:", Robot::loaderAngle->GetAngle());
	SmartDashboard::PutNumber("LOADER flatloader motor current power:", power);
	SmartDashboard::PutNumber("LOADER flatloader encoder current angleAdjustment:", angleAdjustment);
	SmartDashboard::PutNumber("LOADER flatloader encoder current angleError:", angleError);

}

// Make this return true when this Command no longer needs to run execute()
bool LiftLoader::IsFinished()
{
	SmartDashboard::PutNumber("LOADER flatloader encoder previousAngle", previousAngle);
	return ((previousAngle <= overshootNumber + targetAngle) && (previousAngle >= targetAngle - overshootNumber) );

}

// Called once after isFinished returns true
void LiftLoader::End()
{
	Robot::loaderAngle->Move(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to runs
void LiftLoader::Interrupted()
{
	End();
}
