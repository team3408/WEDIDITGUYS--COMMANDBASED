// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"


//Drive 21,22=R  23,24=L
//Climb 25,27
//LoadSpin 26
//loadRaise 33,10

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
CANTalon* RobotMap::loaderSpinSpin = nullptr;
CANTalon* RobotMap::driveCANTalon1 = nullptr;
CANTalon* RobotMap::driveCANTalon2 = nullptr;
CANTalon* RobotMap::driveCANTalon3 = nullptr;
CANTalon* RobotMap::driveCANTalon4 = nullptr;
Encoder* RobotMap::driveQuadratureEncoder1 = nullptr;
Encoder* RobotMap::driveQuadratureEncoder2 = nullptr;
AnalogInput* RobotMap::driveAnalogInput1 = nullptr;
DoubleSolenoid* RobotMap::climberPneumaticsDoubleSolenoid2 = nullptr;
DoubleSolenoid* RobotMap::climberPneumaticsDoubleSolenoid1 = nullptr;
CANTalon* RobotMap::loaderAngleangle = nullptr;

AnalogPotentiometer* RobotMap::loaderAngleAnalogPotentiometer1 = nullptr;
CANTalon* RobotMap::shooterCANTalon1 = nullptr;
CANTalon* RobotMap::climberAngleCANTalon2 = nullptr;
CANTalon* RobotMap::climberAngleCANTalon1 = nullptr;
AnalogPotentiometer* RobotMap::climberAngleAnalogPotentiometer1 = nullptr;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
CANTalon* RobotMap::loaderAngleangle2 = nullptr;
void RobotMap::init() {

	LiveWindow* lw = LiveWindow::GetInstance();

	loaderSpinSpin = new CANTalon(26);
	
	
	driveCANTalon1 = new CANTalon(21);//left
	
	
	driveCANTalon2 = new CANTalon(22);//left
	
	
	driveCANTalon3 = new CANTalon(23);// right
	
	
	driveCANTalon4 = new CANTalon(24);//right
	
	
	driveQuadratureEncoder1 = new Encoder(0, 1, false, Encoder::k4X);
	lw->AddSensor("Drive", "Quadrature Encoder 1", driveQuadratureEncoder1);
	driveQuadratureEncoder1->SetDistancePerPulse(1.0);
        driveQuadratureEncoder1->SetPIDSourceType(PIDSourceType::kDisplacement);
	driveQuadratureEncoder2 = new Encoder(3, 4, false, Encoder::k4X);
	lw->AddSensor("Drive", "Quadrature Encoder 2", driveQuadratureEncoder2);
	driveQuadratureEncoder2->SetDistancePerPulse(1.0);
        driveQuadratureEncoder2->SetPIDSourceType(PIDSourceType::kDisplacement);
	driveAnalogInput1 = new AnalogInput(0);
	lw->AddSensor("Drive", "Analog Input 1", driveAnalogInput1);
	
	climberPneumaticsDoubleSolenoid2 = new DoubleSolenoid(0, 2, 3);      
	lw->AddActuator("ClimberPneumatics", "Double Solenoid 2", climberPneumaticsDoubleSolenoid2);
	
	climberPneumaticsDoubleSolenoid1 = new DoubleSolenoid(0, 0, 1);      
	lw->AddActuator("ClimberPneumatics", "Double Solenoid 1", climberPneumaticsDoubleSolenoid1);
	
	loaderAngleangle = new CANTalon(33);
	loaderAngleangle2 = new CANTalon(10);
	

	loaderAngleAnalogPotentiometer1 = new AnalogPotentiometer(1, 360.0, 0.0);
	lw->AddSensor("loaderAngle", "Analog Potentiometer 1", loaderAngleAnalogPotentiometer1);
	
	//shooterCANTalon1 = new CANTalon(10);
	
	
	climberAngleCANTalon2 = new CANTalon(27);
	
	
	climberAngleCANTalon1 = new CANTalon(25);
	
	
	climberAngleAnalogPotentiometer1 = new AnalogPotentiometer(2, 360.0, 0.0);
	lw->AddSensor("ClimberAngle", "Analog Potentiometer 1", climberAngleAnalogPotentiometer1);
	


}
