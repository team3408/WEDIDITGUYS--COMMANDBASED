#ifndef AutoWithTime_H
#define AutoWithTime_H

#include "Commands/Subsystem.h"
#include "../Robot.h"
#include "WPILib.h"

class AutoWithTime: public Command
{
public:
	AutoWithTime();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
