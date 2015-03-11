#pragma once

#include <directxmath.h>
#include <d3d11_1.h>

#include "GameObject.h"
#include "Structures.h"

using namespace DirectX;
using namespace std;

struct Payload
{
	unsigned type;
	unsigned numberOfParticles;

	void Set(unsigned type, unsigned numberOfParticles)
	{
		Payload::type = type;
		Payload::numberOfParticles = numberOfParticles;
	}
};

struct FireworkRule	// Firework rules that control the length of the fuse and the type of payload
{
	unsigned type;

	RealValue minAge;
	RealValue maxAge;

	XMFLOAT3 minVelocity;
	XMFLOAT3 maxVelocity;

	RealValue damping; // MAY NEED TO REMOVE

	unsigned payloadCount;
	Payload * payloads;
};

class Firework : public GameObject
{
private:
	unsigned _mType;
	RealValue _mAge; // Time before payload is delivered

public:
	Firework(string type, Geometry geometry, Material material, RealValue mass);
	~Firework();

	bool Update(float t);
};