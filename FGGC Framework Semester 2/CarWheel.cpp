#include "CarWheel.h"

CarWheel::CarWheel(string type, Geometry geometry, Material material, RealValue mass, GameObject * parent, XMFLOAT3 posOnCar) : GameObject(type, geometry, material, mass)
{
	GameObject::SetParent(parent);
	_model->GetTransform()->SetPosition(posOnCar);
}

CarWheel::~CarWheel()
{
}

void CarWheel::Update(float t)
{
	GameObject::Update(t);
}

XMFLOAT3 CarWheel::CalculateFowardVelocity()
{
	//	i.	1 RPM = 60 Hz so the 1 rpm will provide 60 * 2 * Pi * radius of linear motion.



	//float arcLength = _rotationalSpeed and _radiusOfWheel;

	//XMFLOAT3 linearVelocity = arcLength / t;

	return{ 0.0f, 0.0f, 0.0f };
}