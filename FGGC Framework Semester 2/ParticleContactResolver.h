#pragma once

#include "ParticleModel.h"
#include "ParticleContact.h"
#include "Structures.h"
#include "XMFLOAT3Methods.h"

class ParticleContactResolver
{
protected:
	unsigned noOfIterations; // This decides how many iterations the resolver will do before stopping
	unsigned iterationsUsed;
public:
	ParticleContactResolver(unsigned noOfIterations);
	void SetIterations(unsigned noOfIterations);
	void ResolveContacts(ParticleContact * contactArray, unsigned numContacts, realValue t);
};