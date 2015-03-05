#pragma once

#include <directxmath.h>
#include <d3d11_1.h>

#include "ParticleModel.h"

using namespace DirectX;

class IForceGenerator
{
public:
	virtual void CalculateForce(ParticleModel* model, RealValue t) = 0;
};