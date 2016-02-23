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
#include "Robot.h"
#include "Commands/AutoDriveForward.h"
#include "Commands/DriveSetDistance.h"


//	https://wpilib.screenstepslive.com/s/3120/m/7932/l/81109-choosing-an-autonomous-program-from-smartdashboard
	Command *autonomousCommand;
	SendableChooser *chooser;


LoaderSpin* Robot::loaderSpin = 0;
Drive* Robot::drive = 0;
ClimberPneumatics* Robot::climberPneumatics = 0;
LoaderAngle* Robot::loaderAngle = 0;
Shooter* Robot::shooter = 0;
ClimberAngle* Robot::climberAngle = 0;
OI* Robot::oi = 0;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION

void Robot::RobotInit() {
	RobotMap::init();

	chooser = new SendableChooser();
	chooser->AddDefault("Default Drive Forward", new AutoDriveForward());//Make sure to Add the Include add the top
	//chooser->AddObject("Unnamed Auto 2", new /*insert auto code name here*/);

	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	loaderSpin = new LoaderSpin();
	drive = new Drive();
	climberPneumatics = new ClimberPneumatics();
	loaderAngle = new LoaderAngle();
	shooter = new Shooter();
	climberAngle = new ClimberAngle();

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	// This MUST be here. If the OI creates Commands (which it very likely
	// will), constructing it during the construction of CommandBase (from
	// which commands extend), subsystems are not guaranteed to be
	// yet. Thus, their requires() statements may grab null pointers. Bad
	// news. Don't move it.
	oi = new OI();
	lw = LiveWindow::GetInstance();

	// instantiate the command used for the autonomous period
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
	autonomousCommand = new AutonomousCommand();

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
  }

/**
 * This function is called when the disabled button is hit.
 * You can use it to reset subsystems before shutting down.
 */
void Robot::DisabledInit(){

}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {
	if (autonomousCommand != NULL)
		autonomousCommand = (Command *) chooser->GetSelected();
		autonomousCommand->Start();
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {

	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to 
	// continue until interrupted by another command, remove
	// these lines or comment it out.
	if (autonomousCommand != NULL)
		autonomousCommand->Cancel();
}

void Robot::TeleopPeriodic() {

	SmartDashboard::PutData("DriveSetDistance", new DriveSetDistance(SmartDashboard::GetNumber("DistanceToDrive",0.0)));
	Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic() {
	lw->Run();
}

START_ROBOT_CLASS(Robot);

