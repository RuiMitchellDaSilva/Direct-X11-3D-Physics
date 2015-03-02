#include "GravityForceGenerator.h"

GravityForceGenerator::GravityForceGenerator(const XMFLOAT3 &gravity)
{

}

GravityForceGenerator::~GravityForceGenerator()
{

}

//XMFLOAT3 CalculateForce(float mass, XMFLOAT3 netForce)
void GravityForceGenerator::CalculateForce(ParticleModel* model, realValue t)
{
	if (model->HasInfiniteMass())
		return;
	model->AddToNetForce(XMFLOAT3Methods::MultiplicationByValue(gravity, model->GetMass()));
}
