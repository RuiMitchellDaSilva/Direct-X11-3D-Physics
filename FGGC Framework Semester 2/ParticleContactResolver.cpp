#include "ParticleContactResolver.h"

ParticleContactResolver::ParticleContactResolver(unsigned noOfIterations) : mNoOfIterations(noOfIterations)
{
}

ParticleContactResolver::~ParticleContactResolver()
{
}

void ParticleContactResolver::ResolveContacts(vector<ParticleContact> contactList, unsigned numContacts, RealValue t)
{
	unsigned i = 0.0f; // Incase while loop isn't entered.

	mIterationsUsed = 0;

	while (mIterationsUsed < mNoOfIterations)
	{
		RealValue max = (RealValue)DBL_MAX;

		unsigned maxIndex = numContacts;

		for (i = 0; i < numContacts; i++)
		{
			RealValue seperatingVelocity = contactList[i].CalculateSeperatingVelocity();

			if (seperatingVelocity < max && (seperatingVelocity < 0 || contactList[i].mPenetration > 0))
			{
				max = seperatingVelocity;
				maxIndex = i;
			}
		}

		if (maxIndex == numContacts)
			break;

		contactList[maxIndex].Resolve(t);

		mIterationsUsed++;
	}
}