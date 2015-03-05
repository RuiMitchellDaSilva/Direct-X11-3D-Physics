#pragma once

#include <directxmath.h>
#include <d3d11_1.h>

#include "XMFLOAT3methods.h"
#include "IForceGenerator.h"

using namespace DirectX;

// Force Generated in the opposite direction to the object sliding down an inclined plane
class GravityForceGenerator : public IForceGenerator
{
private:
	XMFLOAT3 _mGravity;

public:
	GravityForceGenerator(XMFLOAT3 gravity);
	~GravityForceGenerator();

	virtual void CalculateForce(ParticleModel* model, RealValue t);
};