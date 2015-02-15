#pragma once

#include <directxmath.h>
#include <d3d11_1.h>

#include "ParticleModel.h"

using namespace DirectX;

class IForceGenerator
{
	virtual XMFLOAT3 CalculateForce(ParticleModel* model) = 0;
};