#include "ReactionForceGenerator.h"

ReactionForceGenerator::ReactionForceGenerator()
{

}

ReactionForceGenerator::~ReactionForceGenerator()
{

}

//XMFLOAT3 CalculateForce(float mass, XMFLOAT3 netForce)
void ReactionForceGenerator::CalculateForce(ParticleModel* model, realValue t)
{
	XMFLOAT3 force = { 0.0f, 0.0f, 0.0f };
	//force = ReactionForce(model->GetMass(), model->GetAcceleration());
	model->SetVelocity(CalcVelocityChange(model->GetVelocity(), model->GetMass(), force));

	//return SlidingForce(mass, XM_PI / 2, 0.61);
}

XMFLOAT3 ReactionForceGenerator::ReactionForce(float mass, XMFLOAT3 acceleration)
{
	XMFLOAT3 force;

	force = XMFLOAT3Methods::MultiplicationByValue(acceleration, -mass);

	return force;
}

XMFLOAT3 ReactionForceGenerator::CalcVelocityChange(XMFLOAT3 velocity, float mass, XMFLOAT3 impulse)
{
	// Acquire final velocity from momentum equation
	XMFLOAT3 finalVelocity = {0.0f, 0.0f, 0.0f};


	finalVelocity.y = -velocity.y;
	
	//finalVelocity.z = impulse.z; // Momentum - Impulse
	//finalVelocity.x += 0.5 * mass * velocity.x * velocity.x; // Kinetic Energy

	return finalVelocity;
}