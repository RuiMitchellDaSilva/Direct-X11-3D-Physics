#include "ParticleModel.h"

ParticleModel::ParticleModel(Transform* transform, XMFLOAT3 velocity,
	XMFLOAT3 acceleration, float mass, XMFLOAT3 netForce) : _transform(transform), _velocity(velocity), _acceleration(acceleration), _mass(mass), _netForce(netForce)
{
	_collisionRadius = 4.0f;
	//SlidingMotion();
}

ParticleModel::~ParticleModel(void)
{
}

void ParticleModel::MoveConstAccel(float t)
{
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
	UpdateAccel();

	//MoveConstVel(t);
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
}

void ParticleModel::UpdateAccel()
{
	// Calculate acceleration from the net external force
	_acceleration = XMFLOAT3Methods::DivisionByValue(_netForce, _mass);

	if (!_rigid)
		_acceleration.y += -9.81 / 1000;
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