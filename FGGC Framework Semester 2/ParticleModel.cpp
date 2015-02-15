#include "ParticleModel.h"

ParticleModel::ParticleModel(Transform* transform, XMFLOAT3 velocity,
	XMFLOAT3 acceleration, float mass, XMFLOAT3 netForce) : _transform(transform), _velocity(velocity), _acceleration(acceleration), _mass(mass), _netForce(netForce)
{
	//SlidingMotion();
}

ParticleModel::~ParticleModel(void)
{
}

void ParticleModel::MoveConstAccel(float t)
{
	// Update world position of object by adding displacement to
	// previously calculated position
	_transform->SetPosition(_transform->GetPosition().x + (_velocity.x * t) + (0.5f * _acceleration.x  * t * t),
							_transform->GetPosition().y + (_velocity.y * t) + (0.5f * _acceleration.y  * t * t),
							_transform->GetPosition().z + (_velocity.z * t) + (0.5f * _acceleration.z  * t * t));

	// Update velocity of object by adding change relative to previously
	// calculated velocity
	_velocity = { _velocity.x + (_acceleration.x * t),
					_velocity.y + (_acceleration.y * t),
					_velocity.z + (_acceleration.z * t) };
}

void ParticleModel::Update(float t)
{
	UpdateNetForce();
	UpdateAccel();

	//MoveConstVel(t);
	MoveConstAccel(t);
	_transform->Update(t);
}

void ParticleModel::UpdateNetForce()
{
	// Calculate net external force


}

void ParticleModel::AddToNetForce(XMFLOAT3 netForce)
{
	_netForce.x += netForce.x;
	_netForce.y += netForce.y;
	_netForce.z += netForce.z;
}

void ParticleModel::UpdateAccel()
{
	// Calculate acceleration from the net external force
	_acceleration.x = (_netForce.x / _mass);
	_acceleration.y = (_netForce.y / _mass);
	_acceleration.z = (_netForce.z / _mass);

	if (!_rigid)
		_acceleration.y += -9.81 / 1000;
}

