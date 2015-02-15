#include "Transform.h"

Transform::Transform(XMFLOAT3 position, XMFLOAT3 rotation, XMFLOAT3 scale) : _position(position), _rotation(rotation), _scale(scale)
{
}

Transform::~Transform(void)
{
}

void Transform::Update(float t)
{
	// Calculate world matrix
	XMMATRIX scale = XMMatrixScaling(_scale.x, _scale.y, _scale.z);
	XMMATRIX rotation = XMMatrixRotationX(_rotation.x) * XMMatrixRotationY(_rotation.y) * XMMatrixRotationZ(_rotation.z);
	XMMATRIX translation = XMMatrixTranslation(_position.x, _position.y, _position.z);

	XMStoreFloat4x4(&_world, scale * rotation * translation);
}
