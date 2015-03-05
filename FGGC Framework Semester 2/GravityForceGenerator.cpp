#include "GravityForceGenerator.h"

GravityForceGenerator::GravityForceGenerator(XMFLOAT3 gravity) : _mGravity(gravity)
{

}

GravityForceGenerator::~GravityForceGenerator()
{

}

//XMFLOAT3 CalculateForce(float mass, XMFLOAT3 netForce)
void GravityForceGenerator::CalculateForce(ParticleModel* model, RealValue t)
{
	if (model->HasInfiniteMass())
		return;

	model->AddToNetForce(XMFLOAT3Methods::MultiplicationByValue(_mGravity, model->GetMass()));
}
