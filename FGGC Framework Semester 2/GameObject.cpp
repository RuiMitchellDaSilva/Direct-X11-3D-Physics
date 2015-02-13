#include "GameObject.h"

GameObject::GameObject(string type, Geometry geometry, Material material)
{
	_parent = nullptr;
	_model = new ParticleModel(XMFLOAT3(), XMFLOAT3(), XMFLOAT3(1.0f, 1.0f, 1.0f));
	_appearence = new Appearence(geometry, material);
}

GameObject::~GameObject()
{
}

void GameObject::Update(float t)
{
	_model->Update(t);

	if (_parent != nullptr)
		XMStoreFloat4x4(&_model->GetWorld(), _model->GetWorldMatrix() * _parent->_model->GetWorldMatrix());
}
