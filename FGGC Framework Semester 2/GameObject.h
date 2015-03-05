#pragma once

#include <directxmath.h>
#include <d3d11_1.h>

#include "ParticleModel.h"
#include "Appearence.h"

using namespace DirectX;
using namespace std;

class GameObject
{
	private:
		Transform* _transform;
		ParticleModel* _model;
		Appearence* _appearence;

		GameObject * _parent;
	public:
		GameObject(string type, Geometry geometry, Material material, RealValue mass);
		~GameObject();

		ParticleModel* GetParticleModel() const { return _model; }

		Appearence* GetAppearence() const { return _appearence; }

		void SetParent(GameObject * parent) { _parent = parent; }

		void Update(float t);

};

