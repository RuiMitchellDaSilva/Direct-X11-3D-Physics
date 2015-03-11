#pragma once

#include "ParticleModel.h"
#include "ParticleContact.h"
#include "Structures.h"
#include "XMFLOAT3Methods.h"

#include <vector>

class ParticleContactResolver
{
protected:
	unsigned mNoOfIterations = 0; // This decides how many iterations the resolver will do before stopping
	unsigned mIterationsUsed = 0;
public:
	ParticleContactResolver(unsigned noOfIterations);
	~ParticleContactResolver();

	void SetIterations(unsigned noOfIterations){ mNoOfIterations = noOfIterations; }
	void ResolveContacts(vector<ParticleContact> contactList, unsigned numContacts, RealValue t);
};