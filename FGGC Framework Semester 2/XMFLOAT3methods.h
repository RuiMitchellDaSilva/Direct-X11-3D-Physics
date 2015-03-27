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

	RealValue ScalarProduct(XMFLOAT3 first, XMFLOAT3 second);	// AKA Dot/Inner Product
	RealValue ScalarAngleBetweenVectors(XMFLOAT3 first, XMFLOAT3 second);
	XMFLOAT3 VectorProduct(XMFLOAT3 first, XMFLOAT3 second);
	RealValue VectorAngleBetweenVectors(XMFLOAT3 first, XMFLOAT3 second);

	XMFLOAT3 ComponentBoundary(XMFLOAT3 vector, float minValue, float maxValue);	// Keep component values between minimun and maximun values
	XMFLOAT3 MinComponentValue(XMFLOAT3 vector, float value);
	XMFLOAT3 MaxComponentValue(XMFLOAT3 vector, float value);

	XMFLOAT3 Normalize(XMFLOAT3 vector);

	XMFLOAT3 Invert(XMFLOAT3 vector);

	RealValue VectorMagnitude(XMFLOAT3 vector);
};