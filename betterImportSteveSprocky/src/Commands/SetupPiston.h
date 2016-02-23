#ifndef SetupPiston_H
#define SetupPiston_H

#include "../CommandBase.h"
#include "WPILib.h"

class SetupPiston: public CommandBase
{
public:
	SetupPiston();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
