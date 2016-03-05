#ifndef FastFlatLoader_H
#define FastFlatLoader_H

#include "Commands/Subsystem.h"
#include "../Robot.h"
#include "WPILib.h"

class FastFlatLoader: public Command
{
public:
	FastFlatLoader();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
