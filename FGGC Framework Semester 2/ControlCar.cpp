#include "ControlCar.h"

ControlCar::ControlCar(string type, Geometry geometry, Material material) : GameObject(type, geometry, material)
{
}

ControlCar::~ControlCar()
{
}

void ControlCar::Update(float t)
{
	GameObject::Update(t);
}

XMFLOAT3 ControlCar::CalculateFowardVelocity()
{
	//	i.	1 RPM = 60 Hz so the 1 rpm will provide 60 * 2 * Pi * radius of linear motion.



	//float arcLength = _rotationalSpeed and _radiusOfWheel;

	//XMFLOAT3 linearVelocity = arcLength / t;

	return {0.0f, 0.0f, 0.0f};
}