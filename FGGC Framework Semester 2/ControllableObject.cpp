#include "ControllableObject.h"

ControllableObject::ControllableObject(string type, Geometry geometry, Material material, RealValue mass) : GameObject(type, geometry, material, mass)
{
}

ControllableObject::~ControllableObject()
{
}

void ControllableObject::Update(float t)
{
	GameObject::GetParticleModel()->AddToNetForce(_delayedMovement);
	GameObject::Update(t);
	_delayedMovement = { 0.0f, 0.0f, 0.0f };
}

void ControllableObject::MoveObject(Movement moveCommand)
{
	if (moveCommand == UP)
	{
		_delayedMovement = XMFLOAT3Methods::Addition(_delayedMovement, XMFLOAT3(0.0f, 0.1f, 0.0f));
	}
	else if (moveCommand == DOWN)
	{
		_delayedMovement = XMFLOAT3Methods::Addition(_delayedMovement, XMFLOAT3(0.0f, -0.1f, 0.0f));
	}
	else if (moveCommand == FORWARD)
	{
		_delayedMovement = XMFLOAT3Methods::Addition(_delayedMovement, XMFLOAT3(0.0f, 0.0f, 0.1f));
	}
	else if (moveCommand == BACKWARD)
	{
		_delayedMovement = XMFLOAT3Methods::Addition(_delayedMovement, XMFLOAT3(0.0f, 0.0f, -0.1f));
	}
	else if (moveCommand == LEFT)
	{
		_delayedMovement = XMFLOAT3Methods::Addition(_delayedMovement, XMFLOAT3(-0.1f, 0.0f, 0.0f));
	}
	else if (moveCommand == RIGHT)
	{
		_delayedMovement = XMFLOAT3Methods::Addition(_delayedMovement, XMFLOAT3(0.1f, 0.0f, 0.0f));
	}
}


