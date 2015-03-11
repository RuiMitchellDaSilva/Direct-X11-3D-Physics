#pragma once

#include <directxmath.h>
#include <d3d11_1.h>

#include "GameObject.h"

using namespace DirectX;
using namespace std;

class CarWheel : public GameObject
{
private:
	double _radiusOfWheel;
	float _rotationalSpeed;	// Wheel speed, in RPM
	float _roadWheelFrictionCoeff;
	double _steeringAngle;	// Front wheels only

public:
	CarWheel(string type, Geometry geometry, Material material, RealValue mass, GameObject * parent, XMFLOAT3 posOnCar);
	~CarWheel();

	void Update(float t);

	float CalculateRotatSpeed();
	XMFLOAT3 CalculateFowardVelocity();
};