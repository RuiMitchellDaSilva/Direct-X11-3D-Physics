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
protected:
	void Resolve(realValue t);
	realValue CalculateSeperatingVelocity() const;
private:
	void ResolveVelocity(realValue t);

	void ResolveInterpenetration(realValue t);
	realValue penetration;
};