#include "ParticleModel.h"

ParticleModel::ParticleModel(Transform* transform, XMFLOAT3 velocity,
	XMFLOAT3 acceleration, float mass, XMFLOAT3 netForce) : _transform(transform), _velocity(velocity), _acceleration(acceleration), _netForce(netForce)
{
	SetMass(mass);
	_collisionRadius = 0.5f;
	//SlidingMotion();
}

ParticleModel::~ParticleModel(void)
{
}

void ParticleModel::MoveConstAccel(float t)
{
	if (XMFLOAT3Methods::VectorMagnitude(_acceleration) < 0.000001f)
		_acceleration = { 0.0f, 0.0f, 0.0f };

	if (XMFLOAT3Methods::VectorMagnitude(_velocity) < 0.000001f)
		_velocity = { 0.0f, 0.0f, 0.0f };

	// Update world position of object by adding displacement to
	// previously calculated position ( P = P + (V * T) + (0.5 * A * T^2))
	_transform->SetPosition(_transform->GetPosition().x + (_velocity.x * t) + (0.5f * _acceleration.x  * t * t),
		_transform->GetPosition().y + (_velocity.y * t) + (0.5f * _acceleration.y  * t * t),
		_transform->GetPosition().z + (_velocity.z * t) + (0.5f * _acceleration.z  * t * t));

	// Update velocity of object by adding change relative to previously
	// calculated velocity ( V = V + (A * T))
	_velocity = XMFLOAT3Methods::Addition(_velocity, XMFLOAT3Methods::MultiplicationByValue(_acceleration, t));
}

void ParticleModel::Update(float t)
{
	_collisionRadius = 0.5 + XMFLOAT3Methods::VectorMagnitude(_velocity);

	UpdateAccel();

	MoveConstAccel(t);
	_transform->Update(t);
	UpdateNetForce();
}

void ParticleModel::UpdateNetForce()
{
	// Reset net external force
	_netForce = { 0.0f, 0.0f, 0.0f };
}

void ParticleModel::AddToNetForce(XMFLOAT3 netForce)
{
	_netForce = XMFLOAT3Methods::Addition(_netForce, netForce);

	if (_netForce.y == 0.0f)
		int i = 0;
}

void ParticleModel::UpdateAccel()
{
	if (_inverseMass <= 0.0f)
		return;

	// Calculate acceleration from the net external force
	_acceleration = XMFLOAT3Methods::MultiplicationByValue(_netForce, _inverseMass);
}

bool ParticleModel::CollisionCheck(XMFLOAT3 position, float radius)
{
	XMFLOAT3 displacement = {0.0f, 0.0f, 0.0f};

	displacement = XMFLOAT3Methods::Subtraction(position, _transform->GetPosition());

	float displaceMagnitude = XMFLOAT3Methods::VectorMagnitude(displacement);
	float sumOfRadii = radius + GetCollisionRadius();

	if (displaceMagnitude > sumOfRadii)
		return false;
	else
	{

	}

}

void ParticleModel::AngularVelocity()
{
	//feta(angle) = inverse of Inertia * torque;	// Torque : twisting force

	//torque = Pf * force;	// Pf = point at which the force is being applied, relative to the origin of the object.

	//torque = magnitude of torque * unit-length vector in the axis around which the torque applies

	//Ia = sum of n (Mi * d(Pi->a)^2), intial 
	//	n : number of particles, d : distance of particle 'i' from the axis from the axis of rotation
	//	Ia : moment of inertia about the axis


}

void ParticleModel::SetMass(float mass)
{ 
	_mass = mass; 

	if (mass > 0.0f)
		_inverseMass = 1 / _mass;
	else
		_inverseMass = 0.0f;
}

bool ParticleModel::HasInfiniteMass()
{
	if (_mass <= 0.0f)
		return true;
	else
		return false;
}

