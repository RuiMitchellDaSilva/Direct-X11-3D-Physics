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
	_acceleration = XMFLOAT3Methods::ComponentBoundary(_acceleration, 1.0f * pow(10, -7), 0.2f);
	_velocity = XMFLOAT3Methods::ComponentBoundary(_velocity, 1.0f * pow(10, -7), 0.2f);

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
	ConstRotation(t);
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
	if (_inverseMass <= 0.0f)
		return;

	_netForce = XMFLOAT3Methods::ComponentBoundary(_netForce, 1.0f * pow(10, -7), 0.2f);

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

void ParticleModel::SetInertiaTensor(XMFLOAT3 inertiaTensor)
{
	XMFLOAT3 rotation = _transform->GetRotation();

	XMMATRIX rotationMatrix = XMMatrixRotationX(rotation.x) * XMMatrixRotationY(rotation.y) * XMMatrixRotationZ(rotation.z);
	XMMATRIX world = _transform->GetWorldMatrix();
	XMMATRIX body; //= inverseInertiaTensor
	//XMMATRIX body = XMMat

	//RealValue t4 = rotationMatrix

	XMVECTOR t4 = rotationMatrix.r[0] * body.r[0] + rotationMatrix.r[1] * body.r[3] + rotationMatrix.r[2] * body.r[6];

	XMVECTOR t9 = rotationMatrix.r[0] * body.r[1] + rotationMatrix.r[1] * body.r[4] + rotationMatrix.r[2] * body.r[7];

	XMVECTOR t14 = rotationMatrix.r[0] * body.r[2] + rotationMatrix.r[1] * body.r[5] + rotationMatrix.r[2] * body.r[8];


	XMVECTOR t28 = rotationMatrix.r[4] * body.r[0] + rotationMatrix.r[5] * body.r[3] + rotationMatrix.r[6] * body.r[6];
																	   									  
	XMVECTOR t33 = rotationMatrix.r[4] * body.r[1] + rotationMatrix.r[5] * body.r[4] + rotationMatrix.r[6] * body.r[7];
																	   									  
	XMVECTOR t38 = rotationMatrix.r[4] * body.r[2] + rotationMatrix.r[5] * body.r[5] + rotationMatrix.r[6] * body.r[8];


	XMVECTOR t52 = rotationMatrix.r[8] * body.r[0] + rotationMatrix.r[9] * body.r[3] + rotationMatrix.r[10] * body.r[6];
																	   									  
	XMVECTOR t57 = rotationMatrix.r[8] * body.r[1] + rotationMatrix.r[9] * body.r[4] + rotationMatrix.r[10] * body.r[7];
																	   									  
	XMVECTOR t62 = rotationMatrix.r[8] * body.r[2] + rotationMatrix.r[9] * body.r[5] + rotationMatrix.r[10] * body.r[8];


	world.r[0] = (t4 * rotationMatrix.r[0]) + (t9 * rotationMatrix.r[1]) + (t14 * rotationMatrix.r[2]);

	world.r[1] = (t4 * rotationMatrix.r[4]) + (t9 * rotationMatrix.r[5]) + (t14 * rotationMatrix.r[6]);

	world.r[2] = (t4 * rotationMatrix.r[8]) + (t9 * rotationMatrix.r[9]) + (t14 * rotationMatrix.r[10]);


	world.r[3] = (t28 * rotationMatrix.r[0]) + (t33 * rotationMatrix.r[1]) + (t38 * rotationMatrix.r[2]);

	world.r[4] = (t28 * rotationMatrix.r[4]) + (t33 * rotationMatrix.r[5]) + (t38 * rotationMatrix.r[6]);

	world.r[5] = (t28 * rotationMatrix.r[8]) + (t33 * rotationMatrix.r[9]) + (t38 * rotationMatrix.r[10]);


	world.r[6] = (t52 * rotationMatrix.r[0]) + (t57 * rotationMatrix.r[1]) + (t62 * rotationMatrix.r[2]);
				  								 							   
	world.r[7] = (t52 * rotationMatrix.r[4]) + (t57 * rotationMatrix.r[5]) + (t62 * rotationMatrix.r[6]);
				   								 							   
	world.r[8] = (t52 * rotationMatrix.r[8]) + (t57 * rotationMatrix.r[9]) + (t62 * rotationMatrix.r[10]);


}

void ParticleModel::AddForceAtBodyPoint(XMFLOAT3 force, XMFLOAT3 point)
{
	//XMFLOAT3 bodyPoint = GetPointInWorldSpace(point);
	//AddForceAtPoint(force, bodyPoint);

	// No longer resting
}

void ParticleModel::AddForceAtPoint(XMFLOAT3 force, XMFLOAT3 point)
{
	XMFLOAT3 newPoint = point;
	newPoint = XMFLOAT3Methods::Subtraction(newPoint, _transform->GetPosition());

	_netForce = XMFLOAT3Methods::Addition(_netForce, force);
	_netTorque = XMFLOAT3Methods::VectorProduct(_netForce, force);

	// No longer resting
}

void ParticleModel::ConstRotation(float t)
{
	_rotation = XMFLOAT3Methods::MultiplicationByValue(_angularVelocity,  t);

	_transform->SetRotation(XMFLOAT3Methods::Addition(_transform->GetRotation(), _rotation));
}

