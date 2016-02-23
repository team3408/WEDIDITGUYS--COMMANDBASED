#ifndef SetupPiston_H
#define SetupPiston_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class SetupPiston: public Command {
public:
	SetupPiston();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
