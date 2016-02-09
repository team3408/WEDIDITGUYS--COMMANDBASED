#ifndef DriveSetDistance_H
#define DriveSetDistance_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveSetDistance: public CommandBase
{
public:
	DriveSetDistance();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
