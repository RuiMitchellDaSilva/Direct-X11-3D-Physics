#pragma once

#include <directxmath.h>
#include <d3d11_1.h>

#include "GameObject.h"
#include "Structures.h"

using namespace DirectX;
using namespace std;

enum Movement
{
	UP,
	DOWN,
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT
};

class ControllableObject : public GameObject
{
private:
	XMFLOAT3 _delayedMovement = {0.0f, 0.0f, 0.0f};
public:
	ControllableObject(string type, Geometry geometry, Material material, RealValue mass);
	~ControllableObject();

	void MoveObject(Movement moveCommand);

	void Update(float t);
};

