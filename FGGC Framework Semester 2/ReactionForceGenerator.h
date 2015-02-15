#pragma once

#include <directxmath.h>
#include <d3d11_1.h>

#include "IForceGenerator.h"

using namespace DirectX;

// Force Generated in the opposite direction to the object sliding down an inclined plane
class ReactionForceGenerator : public IForceGenerator
{
public :
	ReactionForceGenerator();
	~ReactionForceGenerator();

	//XMFLOAT3 CalculateForce(float mass, XMFLOAT3 netForce)
	XMFLOAT3 CalculateForce(ParticleModel* model);
	XMFLOAT3 ReactionForceGenerator::ReactionForce(float mass, XMFLOAT3 netForce);
	XMFLOAT3 CalcVelocityChange(XMFLOAT3 velocity, float mass, XMFLOAT3 impulse);
};