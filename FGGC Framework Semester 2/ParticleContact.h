#pragma once

#include "ParticleModel.h"
#include "Structures.h"
#include "XMFLOAT3Methods.h"

class ParticleContact
{
public:
	ParticleModel * mModel[2];
	RealValue mRestitution = 0.5f;	// 0 < e < 1
	XMFLOAT3 mContactNormal = XMFLOAT3Methods::Normalize(XMFLOAT3(0.0f, 1.0f, 0.0f));
	RealValue mPenetration;

	// Methods
	ParticleContact();
	~ParticleContact();

	RealValue CalculateSeperatingVelocity() const;
	void Resolve(RealValue t);
	void SetModels(ParticleModel * model1, ParticleModel * model2, RealValue penetration);

protected:
	
private:
	void ResolveVelocity(RealValue t);
	void ResolveInterpenetration(RealValue t);
};