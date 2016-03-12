#ifndef FastSpinIn_H
#define FastSpinIn_H

#include "../Robot.h"
#include "Commands/Subsystem.h"
#include "WPILib.h"

class FastSpinIn: public Command
{
public:
	FastSpinIn();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
