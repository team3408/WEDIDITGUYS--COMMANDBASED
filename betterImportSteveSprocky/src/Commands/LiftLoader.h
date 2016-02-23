#ifndef LiftLoader_H
#define LiftLoader_H


#include "Commands/Subsystem.h"
#include "../Robot.h"
#include "WPILib.h"

class LiftLoader: public Command
{
public:

	LiftLoader();


	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

	float currentAngle;
};

#endif
