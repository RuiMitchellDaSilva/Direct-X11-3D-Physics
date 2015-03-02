#include "ForceRegistry.h"

void ForceRegistry::Add(ParticleModel * model, IForceGenerator * fg)
{
	registrations.push_back({ model, fg });
}

void ForceRegistry::Remove(ParticleModel * model, IForceGenerator * fg)
{
	int i = 0;

	for (; i != registrations.size(); i++)
	{
		if (registrations.at(i).model == model && registrations.at(i).fg == fg)
		{
			registrations.erase(registrations.begin() + i);
			return;
		}
	}
}

void ForceRegistry::Clear()
{
	registrations.clear();
}


void ForceRegistry::CalculateForces(realValue t)
{
	Registry::iterator i = registrations.begin();

	for (; i != registrations.end(); i++)
	{
		i->fg->CalculateForce(i->model, t);
	}
}
