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
	float power;
	const double gain = 0.01;
	const float targetAngle = 135;
	const float overshootNumber = 10;
	float previousAngle;
};

#endif
