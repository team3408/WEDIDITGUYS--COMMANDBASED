// GetotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "OI.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/DefaultDrive.h"
#include "Commands/defaultAngleClimb.h"
#include "Commands/defaultAngleLoader.h"
#include "Commands/extend.h"
#include "Commands/fastDrive.h"
#include "Commands/flatClimb.h"
#include "Commands/flatLoader.h"
#include "Commands/fullClimb.h"
#include "Commands/hitBar.h"
#include "Commands/lowerEverything.h"
#include "Commands/retract.h"
#include "Commands/slowDrive.h"
#include "Commands/spinIn.h"
#include "Commands/spinOut.h"
#include "Commands/setupPiston.h"
#include "Commands/FastFlatLoader.h"


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

OI::OI() {
	// Process operator interface input here.
        // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS

	buttonStick = new Joystick(5);

	allFlat = new JoystickButton(buttonStick, 1);
	allFlat->WhileHeld(new lowerEverything());

	spinnerIn = new JoystickButton(buttonStick, 2);
	spinnerIn->WhileHeld(new spinIn());
	spinnerOut = new JoystickButton(buttonStick, 4);
	spinnerOut->WhileHeld(new spinOut());
	extendPiston = new JoystickButton(buttonStick, 6);
	extendPiston->WhileHeld(new extend());
	retractPiston = new JoystickButton(buttonStick, 5);
	retractPiston->WhileHeld(new retract());
	climbUp = new JoystickButton(buttonStick, 3);
	climbUp->WhileHeld(new fullClimb());
	setupPistonButton = new JoystickButton(buttonStick, 9);
	setupPistonButton->WhileHeld(new setupPiston());
	fastLoader = new JoystickButton(buttonStick, 7);
	fastLoader->WhileHeld(new FastFlatLoader());



	driveStick = new Joystick(0);
	slowMode = new JoystickButton
			(driveStick, 5);
	slowMode->WhileHeld(new slowDrive());
	fastMode = new JoystickButton(driveStick, 6);
	fastMode->WhileHeld(new fastDrive());


        // SmartDashboard Buttons
	SmartDashboard::PutData("Autonomous Command", new AutonomousCommand());

	SmartDashboard::PutData("DefaultDrive", new DefaultDrive());

	SmartDashboard::PutData("fastDrive", new fastDrive());

	SmartDashboard::PutData("slowDrive", new slowDrive());

	SmartDashboard::PutData("defaultAngleLoader", new DefaultAngleLoader());

	SmartDashboard::PutData("spinOut", new spinOut());

	SmartDashboard::PutData("spinIn", new spinIn());

	SmartDashboard::PutData("fullClimb", new fullClimb());

	SmartDashboard::PutData("extend", new extend());

	SmartDashboard::PutData("retract", new retract());

	SmartDashboard::PutData("defaultAngleClimb", new DefaultAngleClimb());

	SmartDashboard::PutData("lowerEverything", new lowerEverything());

	SmartDashboard::PutData("flatClimb", new flatClimb());

	SmartDashboard::PutData("flatLoader", new flatLoader());

	SmartDashboard::PutData("hitBar", new hitBar());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

Joystick* OI::getbuttonStick() {
	return buttonStick;
}

Joystick* OI::getdriveStick() {
	return driveStick;
}

//This way we can change the values easier
double OI::GetLeftDriveThumbStick(){
        return driveStick->GetRawAxis(1);
        //1 is y left
}
double OI::GetRightDriveThumbStick(){
        return driveStick->GetRawAxis(3);
}
double OI::GetLoaderThumbStick(){
        //NUMBER HAS BEEN DOUBLE CHECKED
        return buttonStick->GetRawAxis(1);
}
double OI::GetClimberThumbStick(){
        return buttonStick->GetRawAxis(3);
}

    // END AUTOGENERAGet CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS
