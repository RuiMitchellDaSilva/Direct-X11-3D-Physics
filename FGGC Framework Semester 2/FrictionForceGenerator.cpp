#include "FrictionForceGenerator.h"

FrictionForceGenerator::FrictionForceGenerator()
{

}

FrictionForceGenerator::~FrictionForceGenerator()
{

}

//XMFLOAT3 CalculateForce(float mass, float angle, float coeff)


void FrictionForceGenerator::CalculateForce(ParticleModel* model, realValue t)
{
	//SlidingForce(model->GetMass(), 0.0f, 0.0f);
	//return SlidingForce(mass, XM_PI / 2, 0.61);
}

XMFLOAT3 FrictionForceGenerator::SlidingForce(float mass, float angle, float coeff)
{
	// angle = angle of inclined plane relative to x-axis
	// coeff = friction coefficient

	float magnitude = mass * -9.81f * (sin(angle) - coeff * cos(angle));

	// Check if magnitude is not negative

	XMFLOAT3 force;

	force.x = magnitude * cos(angle);
	force.y = magnitude * sin(angle);
	//force.z = magnitude * cos(angle);
	force.z = 0;

	return force;
}