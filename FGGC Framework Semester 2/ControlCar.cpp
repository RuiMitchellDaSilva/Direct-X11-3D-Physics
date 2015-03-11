#include "ControlCar.h"

ControlCar::ControlCar(string type, Geometry geometry, Material material, RealValue mass) : GameObject(type, geometry, material, mass)
{
	for (int i = 0; i < 4; i++)
		_wheel[i] = new CarWheel("squareWheel", geometry, material, 1.0f, this, {0.0f, 0.0f, 0.0f});
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