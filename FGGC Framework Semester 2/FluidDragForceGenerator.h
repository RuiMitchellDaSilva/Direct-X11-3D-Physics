#pragma once

#include <directxmath.h>
#include <d3d11_1.h>

#include "IForceGenerator.h"

using namespace DirectX;

enum FlowType
{
	Laminar,
	Turbulent
};

// Resistance Force generated 
class FluidDragForceGenerator : public IForceGenerator
{
public:
	FluidDragForceGenerator();
	~FluidDragForceGenerator();

	//XMFLOAT3 CalculateForce(XMFLOAT3 velocity, float angle, float coeff, FlowType flowType)
	void CalculateForce(ParticleModel* model, RealValue t);

	XMFLOAT3 FluidDragForce(XMFLOAT3 velocity, float angle, float coeff, FlowType flowType);
	XMFLOAT3 DragLamFlow(XMFLOAT3 velocity, float coeff);
	XMFLOAT3 DragTurbFlow(XMFLOAT3 velocity, float coeff);
};