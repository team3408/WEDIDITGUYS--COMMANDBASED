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
};

#endif
