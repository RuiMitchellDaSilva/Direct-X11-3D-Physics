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
	XMFLOAT3 CalculateForce(ParticleModel* model);
	XMFLOAT3 FluidDragForceGenerator::FluidDragForce(XMFLOAT3 velocity, float angle, float coeff, FlowType flowType);
	XMFLOAT3 FluidDragForceGenerator::DragLamFlow(XMFLOAT3 velocity, float coeff);
	XMFLOAT3 FluidDragForceGenerator::DragTurbFlow(XMFLOAT3 velocity, float coeff);
};