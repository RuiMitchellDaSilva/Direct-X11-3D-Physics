#include "FluidDragForceGenerator.h"

FluidDragForceGenerator::FluidDragForceGenerator()
{

}

FluidDragForceGenerator::~FluidDragForceGenerator()
{

}

//XMFLOAT3 CalculateForce(XMFLOAT3 velocity, float angle, float coeff, FlowType flowType)
XMFLOAT3 FluidDragForceGenerator::CalculateForce(ParticleModel* model)
{
	return FluidDragForce(model->GetVelocity(), 0.0f, 0.0f, Laminar);
	//return SlidingForce(mass, XM_PI / 2, 0.61);
}

XMFLOAT3 FluidDragForceGenerator::FluidDragForce(XMFLOAT3 velocity, float angle, float coeff, FlowType flowType)
{
	// coeff = drag coefficient

	if (flowType == Laminar)
		return DragLamFlow(velocity, coeff);
	else
		return DragTurbFlow(velocity, coeff);
}

XMFLOAT3 FluidDragForceGenerator::DragLamFlow(XMFLOAT3 velocity, float coeff)
{
	XMFLOAT3 drag;

	drag.x = -coeff * velocity.x;
	drag.y = -coeff * velocity.y;
	drag.z = -coeff * velocity.z;

	return drag;
}

XMFLOAT3 FluidDragForceGenerator::DragTurbFlow(XMFLOAT3 velocity, float coeff)
{
	float velocityMagnitude = sqrtf((velocity.x * velocity.x) + (velocity.y * velocity.y) + (velocity.z * velocity.z));
	XMFLOAT3 unitVectorVelocity = XMFLOAT3(velocity.x / velocityMagnitude, velocity.y / velocityMagnitude, velocity.z / velocityMagnitude);

	float dragMagnitude = coeff * velocityMagnitude * velocityMagnitude;

	XMFLOAT3 drag;

	drag.x = -dragMagnitude * unitVectorVelocity.x;
	drag.y = -dragMagnitude * unitVectorVelocity.y;
	drag.z = -dragMagnitude * unitVectorVelocity.z;

	return drag;
}