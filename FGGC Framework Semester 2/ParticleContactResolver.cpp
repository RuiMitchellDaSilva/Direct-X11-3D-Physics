#include "ParticleContactResolver.h"

ParticleContactResolver::ParticleContactResolver(unsigned noOfIterations)
{

}

void ParticleContactResolver::SetIterations(unsigned noOfIterations)
{

}

void ParticleContactResolver::ResolveContacts(ParticleContact * contactArray, unsigned numContacts, realValue t)
{
	unsigned i = 0.0f; // Incase while loop ins't entered.

	iterationsUsed = 0;

	while (iterationsUsed < noOfIterations)
	{
		realValue max = (realValue)DBL_MAX;

		unsigned maxIndex = numContacts;

		for (i = 0; i < numContacts; i++)
		{
			realValue seperatingVelocity = contactArray[i].CalculateSeperatingVelocity();

			if (seperatingVelocity < max && (seperatingVelocity < 0 || contactArray[i].penetration > 0))
			{
				max = seperatingVelocity;
				maxIndex = i;
			}
		}

		if (maxIndex == numContacts)
			break;

		contactArray[maxIndex].Resolve(t);

		iterationsUsed++;
	}
}