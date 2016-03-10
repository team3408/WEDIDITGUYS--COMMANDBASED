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


LoaderSpin* Robot::loaderSpin = 0;
Drive* Robot::drive = 0;
ClimberPneumatics* Robot::climberPneumatics = 0;
LoaderAngle* Robot::loaderAngle = 0;
Shooter* Robot::shooter = 0;
ClimberAngle* Robot::climberAngle = 0;
OI* Robot::oi = 0;

//Camera Code
//IMAQdxSession session;
//Image *frame;
//IMAQdxError imaqError;
//std::unique_ptr<AxisCamera> camera;
//Image *otherFrame;
CameraServer* usbCamera;




//Light Code
Relay *relay;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION

void Robot::RobotInit() {
	RobotMap::init();

	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	loaderSpin = new LoaderSpin();
	drive = new Drive();
	climberPneumatics = new ClimberPneumatics();
	loaderAngle = new LoaderAngle();
	shooter = new Shooter();
	climberAngle = new ClimberAngle();

	//Start Camera Code
	//frame = imaqCreateImage(IMAQ_IMAGE_RGB, 0);
	// open the camera at the IP address assigned. This is the IP address that the camera
	// can be accessed through the web interface.
	//camera.reset(new AxisCamera("axis-camera.local"));
	//usbCamera = new USBCamera("usbCamera", true);

	usbCamera = CameraServer::GetInstance();
	usbCamera -> SetQuality(50);
	usbCamera -> StartAutomaticCapture("cam1");

	//usbCamera -> OpenCamera();
	//usbCamera -> StartCapture();
	//usbCamera -> GetImage(otherFrame);
	//End Camera Code

	//Start Light Code
	relay = new Relay(0);
	relay->Set(Relay::Value::kOn);
	//End Light Code

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
	chooser = new SendableChooser();
	chooser->AddDefault("Default Drive Forward", new AutoDriveForward());//Make sure to Add the Include add the top
	chooser->AddObject("Unnamed Auto 2", new DriveUnderPort);
	chooser->AddObject("Unnamed Auto 2", new DriveUnderLowbar);


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

	if (autonomousCommand != NULL){
		autonomousCommand = (Command *) chooser->GetSelected();
		autonomousCommand->Start();
	}

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
	float distance1 = 20;
	float distance2 = 50;
	float distance3 = 2;

	SmartDashboard::PutData("DriveSetDistance 20", new DriveSetDistance(distance1));
	SmartDashboard::PutData("DriveSetDistance50", new DriveSetDistance(distance2));
	SmartDashboard::PutData("DriveSetDistance2", new DriveSetDistance(distance3));

}

void Robot::TeleopPeriodic() {
	SmartDashboard::PutNumber("Drive Encoder",drive->Encoders());
	SmartDashboard::PutNumber("LoaderAngle",loaderAngle->GetAngle());

	Scheduler::GetInstance()->Run();

	loaderAngle->DisplayValue();
	//Start Camera Code
	//camera->GetImage(frame);
	//imaqDrawShapeOnImage(frame, frame, { 10, 10, 100, 100 }, DrawMode::IMAQ_DRAW_VALUE, ShapeMode::IMAQ_SHAPE_OVAL, 0.0f);
	//CameraServer::GetInstance()->SetImage(frame);
	//End Camera Code

}

void Robot::TestPeriodic() {
	lw->Run();
}

START_ROBOT_CLASS(Robot);
