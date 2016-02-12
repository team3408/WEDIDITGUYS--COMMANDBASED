// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.




#include "Drive.h"
#include "../RobotMap.h"
#include "WPILib.h"
#include "Encoder.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

Drive::Drive() : Subsystem("Drive") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	cANTalon1 = RobotMap::driveCANTalon1;
	cANTalon2 = RobotMap::driveCANTalon2;
	cANTalon3 = RobotMap::driveCANTalon3;
	cANTalon4 = RobotMap::driveCANTalon4;
	quadratureEncoder1 = RobotMap::driveQuadratureEncoder1;
	quadratureEncoder2 = RobotMap::driveQuadratureEncoder2;
	analogInput1 = RobotMap::driveAnalogInput1;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}
    
void Drive::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new DefaultDrive());
}

void Drive::TwoAxis(float left, float right) {
	cANTalon1->Set(-left);
	cANTalon2->Set(-left);
	cANTalon3->Set(right);
	cANTalon4->Set(right);

}

int Drive::Encoders(){
	int encoder1 = quadratureEncoder1->Get();
	int encoder2 = quadratureEncoder2->Get();
	return quadratureEncoder1;
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
