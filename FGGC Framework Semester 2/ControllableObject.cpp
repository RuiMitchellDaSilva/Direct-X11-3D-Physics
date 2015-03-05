#include "ControllableObject.h"

ControllableObject::ControllableObject(string type, Geometry geometry, Material material, RealValue mass) : GameObject(type, geometry, material, mass)
{
}

ControllableObject::~ControllableObject()
{
}

void ControllableObject::Update(float t)
{
	GameObject::Update(t);
}

void ControllableObject::MoveObject(Movement moveCommand)
{
	if (moveCommand == UP)
	{
		GameObject::GetParticleModel()->AddToNetForce(XMFLOAT3(0.0f, 0.1f, 0.0f));
	}
	else if (moveCommand == DOWN)
	{
		GameObject::GetParticleModel()->AddToNetForce(XMFLOAT3(0.0f, -0.1f, 0.0f));
	}
	else if (moveCommand == FORWARD)
	{
		GameObject::GetParticleModel()->AddToNetForce(XMFLOAT3(0.0f, 0.0f, 0.1f));
	}
	else if (moveCommand == BACKWARD)
	{
		GameObject::GetParticleModel()->AddToNetForce(XMFLOAT3(0.0f, 0.0f, -0.1f));
	}
	else if (moveCommand == LEFT)
	{
		GameObject::GetParticleModel()->AddToNetForce(XMFLOAT3(-0.1f, 0.0f, 0.0f));
	}
	else if (moveCommand == RIGHT)
	{
		GameObject::GetParticleModel()->AddToNetForce(XMFLOAT3(0.1f, 0.0f, 0.0f));
	}
}


