#include "ParticleContact.h"

void ParticleContact::Resolve(realValue t)
{
	ResolveVelocity(t);
	ResolveInterpenetration(t);
}

realValue ParticleContact::CalculateSeperatingVelocity() const
{
	XMFLOAT3 relativeVelocity = model[0]->GetVelocity();

	if (model[1])
		XMFLOAT3Methods::Subtraction(relativeVelocity, model[1]->GetVelocity());

	// MAY NEED TO CHANGE
	return XMFLOAT3Methods::ScalarAngleBetweenVectors(relativeVelocity, contactNormal);
}

void ParticleContact::ResolveVelocity(realValue t) // This works against movable and immovable objects (scenery).
{
	realValue seperatingVelocity = CalculateSeperatingVelocity();

	// Check if it needs to be resolved
	if (seperatingVelocity > 0.0f)	// If true then either seperating/stationary, so no impulse required.
		return;

	realValue newSeperateVelocity = -seperatingVelocity * restitution;

	// This is for the case that the object(s) are resting.
	XMFLOAT3 accCausedVelocity = model[0]->GetAcceleration();

	if (model[1])
		accCausedVelocity = XMFLOAT3Methods::Subtraction(accCausedVelocity, model[0]->GetAcceleration());

	// MAY NEED TO CHANGE Pg 128
	realValue accCausedSepVelocity = XMFLOAT3Methods::VectorMagnitude(XMFLOAT3Methods::Multiplication(accCausedVelocity, contactNormal)) * t;

	if (accCausedSepVelocity < 0.0f)
	{
		newSeperateVelocity += restitution * accCausedSepVelocity;

		if (newSeperateVelocity < 0.0f)
			newSeperateVelocity = 0.0f;
	}



	realValue deltaVelocity = newSeperateVelocity - seperatingVelocity;

	realValue totalInverseMass = model[0]->GetInverseMass();

	if (model[1])
		totalInverseMass += model[1]->GetInverseMass();

	// If all particles have infinite mass, impulse won't effect.
	if (totalInverseMass <= 0.0f)
		return;

	realValue impulse = deltaVelocity / totalInverseMass;

	XMFLOAT3 impulsePerIMass = XMFLOAT3Methods::MultiplicationByValue(contactNormal, impulse);

	// Apply impulses
	model[0]->SetVelocity(XMFLOAT3Methods::Addition(model[0]->GetVelocity(),
		XMFLOAT3Methods::MultiplicationByValue(impulsePerIMass, model[0]->GetInverseMass())));

	if (model[1])
		model[1]->SetVelocity(XMFLOAT3Methods::Addition(model[1]->GetVelocity(),
		XMFLOAT3Methods::MultiplicationByValue(impulsePerIMass, model[1]->GetInverseMass())));
}

void ParticleContact::ResolveInterpenetration(realValue t)
{
	if (penetration <= 0.0f)
		return;

	realValue totalInverseMass = model[0]->GetInverseMass();

	if (model[1])
		totalInverseMass += model[1]->GetInverseMass();

	if (totalInverseMass <= 0.0f)
		return;

	XMFLOAT3 movePerIMass = XMFLOAT3Methods::MultiplicationByValue(contactNormal, (penetration / totalInverseMass));

	model[0]->GetTransform()->SetPosition(XMFLOAT3Methods::Addition(model[0]->GetTransform()->GetPosition(),
		(XMFLOAT3Methods::MultiplicationByValue(movePerIMass, model[0]->GetInverseMass()))));

	if (model[1])
		model[1]->GetTransform()->SetPosition(XMFLOAT3Methods::Addition(model[1]->GetTransform()->GetPosition(),
		(XMFLOAT3Methods::MultiplicationByValue(movePerIMass, -model[1]->GetInverseMass())))); 
}