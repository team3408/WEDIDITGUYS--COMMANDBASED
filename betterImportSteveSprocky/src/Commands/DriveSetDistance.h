#ifndef DriveSetDistance_H
#define DriveSetDistance_H

#include "Commands/Subsystem.h"
#include "../Robot.h"
#include "WPILib.h"

class DriveSetDistance: public Command
{
public:
	DriveSetDistance(double Distance);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	   float left;
	   float right;
	   float power;
		float midPower = 0.66;

	   float currentDistance;
	   int currentEncCountLeft;
	   int currentEncCountRight;

	   int overshootNumber = 100;


	   float targetDistance;
	   const float encoderCountsPerRotation = 360;
	   const float diameter = 7.6;						// 7.6 inches is the diameter of our robot
	   const float circumference = diameter *3.14159;
	   float EncErrorLeft;
	   float targetEncoderCounts;
	   int initialEncCountLeft;
		double gain = 0.01;

};

#endif
