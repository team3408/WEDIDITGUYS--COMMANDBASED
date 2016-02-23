#ifndef setupPiston_H
#define setupPiston_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class setupPiston: public Command
{
public:
	setupPiston();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
