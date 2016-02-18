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
};

#endif
