#include "ParticleContact.h"

ParticleContact::ParticleContact()
{
}

ParticleContact::~ParticleContact()
{
}

void ParticleContact::SetModels(ParticleModel * model1, ParticleModel * model2)
{
	mModel[0] = model1;
	mModel[1] = model2;
}

void ParticleContact::Resolve(RealValue t)
{
	ResolveVelocity(t);
	ResolveInterpenetration(t);
}

RealValue ParticleContact::CalculateSeperatingVelocity() const
{
	XMFLOAT3 relativeVelocity = mModel[0]->GetVelocity();

	if (mModel[1])
		XMFLOAT3Methods::Subtraction(relativeVelocity, mModel[1]->GetVelocity());

	return XMFLOAT3Methods::ScalarProduct(relativeVelocity, mContactNormal);
}

void ParticleContact::ResolveVelocity(RealValue t) // This works against movable and immovable objects (scenery).
{
	RealValue seperatingVelocity = CalculateSeperatingVelocity();

	// Check if it needs to be resolved
	if (seperatingVelocity > 0.0f)	// If true then either seperating/stationary, so no impulse required.
		return;

	RealValue newSeperateVelocity = -seperatingVelocity * mRestitution;

	// This is for the case that the object(s) are resting.
	XMFLOAT3 accCausedVelocity = mModel[0]->GetAcceleration();

	if (mModel[1])
		accCausedVelocity = XMFLOAT3Methods::Subtraction(accCausedVelocity, mModel[1]->GetAcceleration());

	// MAY NEED TO CHANGE Pg 128
	RealValue accCausedSepVelocity = XMFLOAT3Methods::ScalarProduct(accCausedVelocity, mContactNormal) * t;

	if (accCausedSepVelocity < 0.0f)
	{
		newSeperateVelocity += mRestitution * accCausedSepVelocity;

		if (newSeperateVelocity < 0.0f)	
			newSeperateVelocity = 0.0f;
	}

	RealValue deltaVelocity = newSeperateVelocity - seperatingVelocity;

	RealValue totalInverseMass = mModel[0]->GetInverseMass();

	if (mModel[1])
		totalInverseMass += mModel[1]->GetInverseMass();

	// If all particles have infinite mass, impulse won't effect.
	if (totalInverseMass <= 0.0f)
		return;

	RealValue impulse = deltaVelocity / totalInverseMass;

	XMFLOAT3 impulsePerIMass = XMFLOAT3Methods::MultiplicationByValue(mContactNormal, impulse);

	// Apply impulses
	mModel[0]->SetVelocity(XMFLOAT3Methods::Addition(mModel[0]->GetVelocity(),
		XMFLOAT3Methods::MultiplicationByValue(impulsePerIMass, mModel[0]->GetInverseMass())));

	if (mModel[1])
		mModel[1]->SetVelocity(XMFLOAT3Methods::Addition(mModel[1]->GetVelocity(),
		XMFLOAT3Methods::MultiplicationByValue(impulsePerIMass, mModel[1]->GetInverseMass())));
}

void ParticleContact::ResolveInterpenetration(RealValue t)
{
	if (mPenetration <= 0.0f)
		return;

	RealValue totalInverseMass = mModel[0]->GetInverseMass();

	if (mModel[1])
		totalInverseMass += mModel[1]->GetInverseMass();

	if (totalInverseMass <= 0.0f)
		return;

	XMFLOAT3 movePerIMass = XMFLOAT3Methods::MultiplicationByValue(mContactNormal, (mPenetration / totalInverseMass));

	mModel[0]->GetTransform()->SetPosition(XMFLOAT3Methods::Addition(mModel[0]->GetTransform()->GetPosition(),
		(XMFLOAT3Methods::MultiplicationByValue(movePerIMass, mModel[0]->GetInverseMass()))));

	if (mModel[1])
		mModel[1]->GetTransform()->SetPosition(XMFLOAT3Methods::Addition(mModel[1]->GetTransform()->GetPosition(),
		(XMFLOAT3Methods::MultiplicationByValue(movePerIMass, -mModel[1]->GetInverseMass())))); 
}