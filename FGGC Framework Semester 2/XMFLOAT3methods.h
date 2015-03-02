#pragma once

#include <directxmath.h>
#include <d3d11_1.h>
#include "Structures.h"

using namespace DirectX;

namespace XMFLOAT3Methods
{
	XMFLOAT3 Addition(XMFLOAT3 first, XMFLOAT3 second);
	XMFLOAT3 Subtraction(XMFLOAT3 first, XMFLOAT3 second);
	XMFLOAT3 Multiplication(XMFLOAT3 first, XMFLOAT3 second); // AKA Component Product
	XMFLOAT3 Division(XMFLOAT3 first, XMFLOAT3 second);

	XMFLOAT3 AdditionByValue(XMFLOAT3 vector, float value);
	XMFLOAT3 SubtractionByValue(XMFLOAT3 vector, float value);
	XMFLOAT3 MultiplicationByValue(XMFLOAT3 vector, float value);
	XMFLOAT3 DivisionByValue(XMFLOAT3 vector, float value);

	XMFLOAT3 ZeroVector(XMFLOAT3 vector);

	realValue ScalarProduct(XMFLOAT3 first, XMFLOAT3 second);	// AKA Dot/Inner Product
	realValue ScalarAngleBetweenVectors(XMFLOAT3 first, XMFLOAT3 second);
	XMFLOAT3 VectorProduct(XMFLOAT3 first, XMFLOAT3 second);
	realValue VectorAngleBetweenVectors(XMFLOAT3 first, XMFLOAT3 second);

	XMFLOAT3 Invert(XMFLOAT3 vector);

	realValue VectorMagnitude(XMFLOAT3 vector);
};