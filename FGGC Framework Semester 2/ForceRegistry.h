#pragma once

#include <directxmath.h>
#include <d3d11_1.h>

#include <vector>

#include "ParticleModel.h"
#include "IForceGenerator.h"

using namespace DirectX;
using namespace std;

class ForceRegistry
{
protected:

	struct ForceRegistration
	{
		ParticleModel * model;
		IForceGenerator * fg;
	};

	typedef std::vector<ForceRegistration> Registry;
	Registry registrations;

public:
	void Add(ParticleModel * model, IForceGenerator * fg);
	void Remove(ParticleModel * model, IForceGenerator * fg);
	void Clear();
	void CalculateForces(realValue t);
};