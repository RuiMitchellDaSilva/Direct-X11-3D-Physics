#pragma once

#include "ParticleModel.h"
#include "Structures.h"
#include "XMFLOAT3Methods.h"

class ParticleContact
{
public:
	ParticleModel * model[2];
	realValue restitution;
	XMFLOAT3 contactNormal;
	realValue penetration;
	realValue CalculateSeperatingVelocity() const;
	void Resolve(realValue t);

protected:
	
	
private:
	void ResolveVelocity(realValue t);
	void ResolveInterpenetration(realValue t);
};