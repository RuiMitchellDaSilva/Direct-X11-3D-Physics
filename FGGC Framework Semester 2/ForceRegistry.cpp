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
	for (int i = 0; i < mRegistrations.size(); i++)
	{
		if (mRegistrations.at(i).model == model)
			if (mRegistrations.at(i).fg == fg)
				{
					mRegistrations.erase(mRegistrations.begin() + i);
					i--;
				}
	}
}

bool ForceRegistry::Find(ParticleModel * model, IForceGenerator * fg)
{
	for (int i = 0; i < mRegistrations.size(); i++)
	{
		if (mRegistrations.at(i).model == model)
			if (mRegistrations.at(i).fg == fg)
			{
				return true;
			}
	}
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
