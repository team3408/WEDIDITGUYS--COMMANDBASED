#ifndef FastSpinOut_H
#define FastSpinOut_H


#include "../Robot.h"
#include "Commands/Subsystem.h"
#include "WPILib.h"

class FastSpinOut: public Command
{
public:
	FastSpinOut();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
