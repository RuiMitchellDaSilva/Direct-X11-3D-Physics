#include "ForceRegistry.h"

ForceRegistry::ForceRegistry()
{
}

ForceRegistry::~ForceRegistry()
{
}

void ForceRegistry::UpdateForces(realValue t)
{
	Registry::iterator i = registrations.begin();

	for (; i != registrations.end(); i++)
	{
		i->fg->UpdateForce(i->model, t);
	}
}
