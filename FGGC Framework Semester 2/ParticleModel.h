#pragma once

#include <directxmath.h>
#include <d3d11_1.h>

#include <string>
#include "Transform.h"
#include "XMFLOAT3methods.h"
#include "Structures.h"

#include <complex>

using namespace DirectX;
using namespace std;



class ParticleModel
{
private:		
	Transform* _transform;
	XMFLOAT3 _velocity;
	XMFLOAT3 _acceleration;
	realValue _mass; // Measured in kilograms (THIS MUST NEVER BE ZERO)
	realValue _inverseMass;
	XMFLOAT3 _netForce;
	bool _rigid = true;
	bool _collidability = true;
	float _collisionRadius;


	// std::real
	double _linearDamping;
	//Quaternion _orientation;
	XMFLOAT3 _rotation;
	//Matrix4 _transformMatrix;

	realValue _damping = 1.0f;



public:
	ParticleModel(Transform* transform, XMFLOAT3 velocity, XMFLOAT3 acceleration, float mass, XMFLOAT3 netForce);
	~ParticleModel();

	Transform* GetTransform() const { return _transform; }

	XMFLOAT3 GetVelocity() const { return _velocity; }
	void SetVelocity(XMFLOAT3 velocity) { _velocity = velocity; }

	XMFLOAT3 GetAcceleration() const { return _acceleration; }
	void SetAcceleration(XMFLOAT3 acceleration) { _acceleration = acceleration; }
	void MoveConstAccel(float t);
	void UpdateAccel();

	float GetMass() const { return _mass; }
	void SetMass(float mass);
	realValue GetInverseMass(){ return _inverseMass; }
	bool HasInfiniteMass();

	XMFLOAT3 GetNetForce() const { return _netForce; }
	void SetNetForce(XMFLOAT3 netForce) { _netForce = netForce; }
	void AddToNetForce(XMFLOAT3 netForce);
	void UpdateNetForce();

	void SetRigid(bool isObjectRigid) { _rigid = isObjectRigid; }
	bool IsRigid() { return _rigid; }

	bool CollisionCheck(XMFLOAT3 position, float radius);
	float GetCollisionRadius() { return _collisionRadius; }
	void SetCollidability(bool collidability){ _collidability = collidability; }
	bool GetCollidability(){ return _collidability; }

	void AngularVelocity();
	//string GetType() const { return _type; }

	void Update(float t);
};