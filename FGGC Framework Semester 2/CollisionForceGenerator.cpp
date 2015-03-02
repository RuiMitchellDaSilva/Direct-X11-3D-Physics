#include "CollisionForceGenerator.h"

CollisionForceGenerator::CollisionForceGenerator()
{

}

CollisionForceGenerator::~CollisionForceGenerator()
{

}

void CollisionForceGenerator::CalculateForce(ParticleModel* model, realValue t)
{
	//CollisionForce(model1, model2);

	//return {0.0f, 0.0f, 0.0f};
}

void CollisionForceGenerator::CollisionForce(ParticleModel* model1, ParticleModel* model2)
{
	XMFLOAT3 momentum1 = XMFLOAT3Methods::MultiplicationByValue(model1->GetVelocity(), model1->GetMass());
	XMFLOAT3 momentum2 = XMFLOAT3Methods::MultiplicationByValue(model2->GetVelocity(), model2->GetMass());

	CalcVelocityChange(model1, model2);

	// Impulse is the change in momentum
	XMFLOAT3 force1 = XMFLOAT3Methods::Subtraction(momentum1, XMFLOAT3Methods::MultiplicationByValue(model1->GetVelocity(), model1->GetMass()));
	XMFLOAT3 force2 = XMFLOAT3Methods::Subtraction(momentum2, XMFLOAT3Methods::MultiplicationByValue(model2->GetVelocity(), model2->GetMass()));

	model1->AddToNetForce(force1);
	model2->AddToNetForce(force2);
}

void CollisionForceGenerator::CalcVelocityChange(ParticleModel* model1, ParticleModel* model2)
{
	float mass1 = model1->GetMass();
	float mass2 = model2->GetMass();
	XMFLOAT3 velocity1 = model1->GetVelocity();
	XMFLOAT3 velocity2 = model2->GetVelocity();

	//m1v1 + m2v2 = m1v1 + m2v2

	const float coeff = 1.0f;

	// V1f - V2f = -E(V1i - V2i)	Coefficient of restitution
	XMFLOAT3 tempVelocity1 = XMFLOAT3Methods::MultiplicationByValue(velocity1, -coeff);
	XMFLOAT3 tempVelocity2 = XMFLOAT3Methods::MultiplicationByValue(velocity2, -coeff);

	model1->SetVelocity(tempVelocity1);
	model2->SetVelocity(tempVelocity2);
}