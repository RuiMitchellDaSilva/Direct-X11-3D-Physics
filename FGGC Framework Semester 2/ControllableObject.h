#pragma once

#include <directxmath.h>
#include <d3d11_1.h>

#include "GameObject.h"

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

public:
	ControllableObject(string type, Geometry geometry, Material material);
	~ControllableObject();

	void MoveObject(Movement moveCommand);

	void Update(float t);
};

