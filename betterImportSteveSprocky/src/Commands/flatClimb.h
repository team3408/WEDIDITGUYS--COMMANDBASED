#ifndef FLATCLIMB_H
#define FLATCLIMB_H


#include "Commands/Subsystem.h"
#include "../Robot.h"


class flatClimb: public Command {
public:
	flatClimb();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

	float currentAngle;
	float targetAngle = 95;		// target angle is 95 degrees because down is 90
	float angleAdjustment;
	double power;
	float gain = 0.008;
	float angleError;
	float overshootNumber = 10;

};

#endif
