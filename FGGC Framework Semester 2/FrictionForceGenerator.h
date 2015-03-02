#pragma once

#include <directxmath.h>
#include <d3d11_1.h>

#include "IForceGenerator.h"

using namespace DirectX;

// Force Generated in the opposite direction to the object sliding down an inclined plane
class FrictionForceGenerator : public IForceGenerator
{
public:
	FrictionForceGenerator();
	~FrictionForceGenerator();

	void CalculateForce(ParticleModel* model, realValue t);
	//XMFLOAT3 CalculateForce(ParticleModel* model);
	XMFLOAT3 FrictionForceGenerator::SlidingForce(float mass, float angle, float coeff);

};