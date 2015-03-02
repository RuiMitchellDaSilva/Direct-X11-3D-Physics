#pragma once

#include <directxmath.h>
#include <d3d11_1.h>

#include "XMFLOAT3methods.h"
#include "IForceGenerator.h"

using namespace DirectX;

// Force Generated in the opposite direction to the object sliding down an inclined plane
class ReactionForceGenerator : public IForceGenerator
{
public :
	ReactionForceGenerator();
	~ReactionForceGenerator();

	void CalculateForce(ParticleModel* model, realValue t);
	//XMFLOAT3 CalculateForce(ParticleModel* model);
	XMFLOAT3 ReactionForce(float mass, XMFLOAT3 netForce);
	XMFLOAT3 CalcVelocityChange(XMFLOAT3 velocity, float mass, XMFLOAT3 impulse);
};