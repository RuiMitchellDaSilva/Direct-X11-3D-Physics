#pragma once

#include <directxmath.h>
#include <d3d11_1.h>

using namespace DirectX;
using namespace std;

struct Geometry
{
	ID3D11Buffer * vertexBuffer;
	ID3D11Buffer * indexBuffer;
	int numberOfIndices;

	UINT vertexBufferStride;
	UINT vertexBufferOffset;
};

struct Material
{
	XMFLOAT4 diffuse;
	XMFLOAT4 ambient;
	XMFLOAT4 specular;
	float specularPower;
};

class Appearence
{
public:
	Appearence(Geometry geometry, Material material);
	~Appearence();

	Geometry GetGeometryData() const { return _mGeometry; }

	Material GetMaterial() const { return _mMaterial; }

	void SetTextureRV(ID3D11ShaderResourceView * textureRV) { _textureRV = textureRV; }
	ID3D11ShaderResourceView * GetTextureRV() const { return _textureRV; }
	bool HasTexture() const { return _textureRV ? true : false; }

	void Draw(ID3D11DeviceContext * pImmediateContext);

private:
	Geometry _mGeometry;
	Material _mMaterial;
	ID3D11ShaderResourceView * _textureRV;
};