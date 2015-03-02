#pragma once

#include <directxmath.h>
#include <d3d11_1.h>

#include "IForceGenerator.h"

using namespace DirectX;

// Force Generated in the opposite direction to the object sliding down an inclined plane
class CollisionForceGenerator : public IForceGenerator
{
public:
	CollisionForceGenerator();
	~CollisionForceGenerator();

	void CalculateForce(ParticleModel* model, realValue t);

	void CollisionForce(ParticleModel* model1, ParticleModel* model2);
	void CalcVelocityChange(ParticleModel* model1, ParticleModel* model2);
};