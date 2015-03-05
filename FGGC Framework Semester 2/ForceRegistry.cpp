#include "ForceRegistry.h"

ForceRegistry::ForceRegistry()
{
}

ForceRegistry::~ForceRegistry()
{
}

void ForceRegistry::Add(ParticleModel * model, IForceGenerator * fg)
{
	ForceRegistration forceRegistry = { model, fg };

	mRegistrations.push_back({ model, fg });
}

void ForceRegistry::Remove(ParticleModel * model, IForceGenerator * fg)
{

}

void ForceRegistry::Clear()
{
	//registrations.clear();
}


void ForceRegistry::CalculateForces(RealValue t)
{
	Registry::iterator i = mRegistrations.begin();

	for (; i != mRegistrations.end(); i++)
	{
		i->fg->CalculateForce(i->model, t);
	}
}
