#pragma once

#include <directxmath.h>
#include <d3d11_1.h>
#include <string>

#include "ParticleModel.h"
#include "Appearence.h"

using namespace DirectX;
using namespace std;

class GameObject
{
public:
	GameObject(string type, Geometry geometry, Material material);
	~GameObject();

	ParticleModel* GetParticleModel() const { return _model; }

	Appearence* GetAppearence() const { return _appearence; }

	void SetParent(GameObject * parent) { _parent = parent; }

	void Update(float t);

private:
	ParticleModel* _model;
	Appearence* _appearence;

	GameObject * _parent;
};

