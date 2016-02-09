// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef ROBOTMAP_H
#define ROBOTMAP_H
#include "WPILib.h"

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
class RobotMap {
public:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	static CANTalon* loaderSpinSpin;
	static CANTalon* driveCANTalon1;
	static CANTalon* driveCANTalon2;
	static CANTalon* driveCANTalon3;
	static CANTalon* driveCANTalon4;
	static Encoder* driveQuadratureEncoder1;
	static Encoder* driveQuadratureEncoder2;
	static AnalogInput* driveAnalogInput1;
	static DoubleSolenoid* climberPneumaticsDoubleSolenoid2;
	static DoubleSolenoid* climberPneumaticsDoubleSolenoid1;
	static CANTalon* loaderAngleangle;

	static AnalogPotentiometer* loaderAngleAnalogPotentiometer1;
	static CANTalon* shooterCANTalon1;
	static CANTalon* climberAngleCANTalon2;
	static CANTalon* climberAngleCANTalon1;
	static AnalogPotentiometer* climberAngleAnalogPotentiometer1;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	static CANTalon* loaderAngleangle2;

	static void init();
};
#endif
