#pragma once

#include <directxmath.h>
#include <d3d11_1.h>

#include "GameObject.h"

using namespace DirectX;
using namespace std;

class ControlCar : public GameObject
{
private:
	double _radiusOfWheel;
	float _rotationalSpeed;	// Wheel speed, in RPM
	//Gear _gearRatio;
	float _engineSpeed; // In RPM
	float _roadWheelFrictionCoeff;
	float _engineThrust;
	double _steeringAngle;	// Front wheels only

public:
	ControlCar(string type, Geometry geometry, Material material, realValue mass);
	~ControlCar();

	void Update(float t);

	void SetEngineSpeed(float engineSpeed){ _engineSpeed = engineSpeed; }
	void SetEngineThrust(float engineThrust){ _engineThrust = engineThrust; }
	float CalculateRotatSpeed();
	XMFLOAT3 CalculateFowardVelocity();


};