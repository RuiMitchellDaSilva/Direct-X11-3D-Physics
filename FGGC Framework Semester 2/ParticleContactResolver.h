#pragma once

#include "ParticleModel.h"
#include "ParticleContact.h"
#include "Structures.h"
#include "XMFLOAT3Methods.h"

class ParticleContactResolver
{
protected:
	unsigned mNoOfIterations; // This decides how many iterations the resolver will do before stopping
	unsigned mIterationsUsed;
public:
	ParticleContactResolver(unsigned noOfIterations);
	~ParticleContactResolver();

	void SetIterations(unsigned noOfIterations){ mNoOfIterations = noOfIterations; }
	void ResolveContacts(ParticleContact * contactArray, unsigned numContacts, RealValue t);
};