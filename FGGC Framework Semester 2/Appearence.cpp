#include "Appearence.h"

Appearence::Appearence(Geometry geometry, Material material) : _mGeometry(geometry), _mMaterial(material)
{
}

Appearence::~Appearence()
{
}

void Appearence::Draw(ID3D11DeviceContext * pImmediateContext)
{
	// NOTE: We are assuming that the constant buffers and all other draw setup has already taken place

	// Set vertex and index buffers
	pImmediateContext->IASetVertexBuffers(0, 1, &_mGeometry.vertexBuffer, &_mGeometry.vertexBufferStride, &_mGeometry.vertexBufferOffset);
	pImmediateContext->IASetIndexBuffer(_mGeometry.indexBuffer, DXGI_FORMAT_R16_UINT, 0);

	pImmediateContext->DrawIndexed(_mGeometry.numberOfIndices, 0, 0);
}