// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.



#include "WPILib.h"
#include "loaderAngle.h"
#include "defaultAngleLoader.h"// This fixes the cant find thing error
#include "../RobotMap.h"
#include "WPILib.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

LoaderAngle::LoaderAngle() : Subsystem("loaderAngle") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	angle = RobotMap::loaderAngleangle;
	angle2 = RobotMap::loaderAngleangle2;
	analogPotentiometer1 = RobotMap::loaderAngleAnalogPotentiometer1;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}
    
void LoaderAngle::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new DefaultAngleLoader());
}

void LoaderAngle::Move(float value) {
	angle->Set(value);
	angle2->Set(-value);//
}


float LoaderAngle::GetAngle() {
	float output = analogPotentiometer1->Get();
	return output;
}

void LoaderAngle::Stop() {
	angle->Set(0);
}


// Put methods for controlling this subsystem
// here. Call these from Commands.

