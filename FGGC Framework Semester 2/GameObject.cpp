#include "GameObject.h"

GameObject::GameObject(string type, Geometry geometry, Material material)
{
	_parent = nullptr;
	_transform = new Transform(XMFLOAT3(), XMFLOAT3(), XMFLOAT3(1.0f, 1.0f, 1.0f));
	_model = new ParticleModel(_transform, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 10.0f, { 0.0f, 0.0f, 0.0f });
	_appearence = new Appearence(geometry, material);
}

GameObject::~GameObject()
{
}

void GameObject::Update(float t)
{
	_model->Update(t);

	if (_parent != nullptr)
		XMStoreFloat4x4(&_model->GetTransform()->GetWorld(),
							_model->GetTransform()->GetWorldMatrix()
								* _parent->_model->GetTransform()->GetWorldMatrix());
}
