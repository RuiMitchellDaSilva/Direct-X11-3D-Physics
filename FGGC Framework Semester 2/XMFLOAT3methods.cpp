#define _CRT_SECURE_NO_DEPRECATE

#include "XMFLOAT3Methods.h"

namespace XMFLOAT3Methods
{
	XMFLOAT3 Addition(XMFLOAT3 first, XMFLOAT3 second)
	{
		first.x += second.x;
		first.y += second.y;
		first.z += second.z;

		return first;
	}

	XMFLOAT3 Subtraction(XMFLOAT3 first, XMFLOAT3 second)
	{
		first.x -= second.x;
		first.y -= second.y;
		first.z -= second.z;

		return first;
	}

	XMFLOAT3 Multiplication(XMFLOAT3 first, XMFLOAT3 second)
	{
		first.x *= second.x;
		first.y *= second.y;
		first.z *= second.z;

		return first;
	}

	XMFLOAT3 Division(XMFLOAT3 first, XMFLOAT3 second)
	{
		first.x /= second.x;
		first.y /= second.y;
		first.z /= second.z;

		return first;
	}

	XMFLOAT3 AdditionByValue(XMFLOAT3 vector, float value)
	{
		vector.x += value;
		vector.y += value;
		vector.z += value;

		return vector;
	}

	XMFLOAT3 SubtractionByValue(XMFLOAT3 vector, float value)
	{
		vector.x -= value;
		vector.y -= value;
		vector.z -= value;

		return vector;
	}

	XMFLOAT3 MultiplicationByValue(XMFLOAT3 vector, float value)
	{
		vector.x *= value;
		vector.y *= value;
		vector.z *= value;

		return vector;
	}

	XMFLOAT3 DivisionByValue(XMFLOAT3 vector, float value)
	{
		vector.x /= value;
		vector.y /= value;
		vector.z /= value;

		return vector;
	}

	RealValue VectorMagnitude(XMFLOAT3 vector)
	{
		return sqrtf((vector.x * vector.x) + (vector.y * vector.y) + (vector.z * vector.z));
	}

	RealValue ScalarProduct(XMFLOAT3 first, XMFLOAT3 second)
	{
		return (first.x * second.x) + (first.y * second.y) + (first.z * second.z);
	}

	RealValue ScalarAngleBetweenVectors(XMFLOAT3 first, XMFLOAT3 second)
	{
		RealValue scalarProduct = ScalarProduct(first, second);
		RealValue magnitudes = VectorMagnitude(first) * VectorMagnitude(second);
		return (RealValue)acos(scalarProduct / magnitudes);
	}

	XMFLOAT3 VectorProduct(XMFLOAT3 first, XMFLOAT3 second)
	{
		XMFLOAT3 vector = { 0.0f, 0.0f, 0.0f };
		vector.x = (first.y * second.z) - (first.z * second.y);
		vector.y = (first.z * second.x) - (first.x * second.z);
		vector.z = (first.x * second.y) - (first.y * second.x);

		return vector;
	}

	RealValue VectorAngleBetweenVectors(XMFLOAT3 first, XMFLOAT3 second)
	{
		//real scalarProduct = ScalarProduct(first, second);
		//real magnitudes = VectorMagnitude(first) * VectorMagnitude(second);
		//return (real)acos(scalarProduct / magnitudes);

		return 0.0f;
	}

	XMFLOAT3 Invert(XMFLOAT3 vector)
	{
		vector.x = -vector.x;
		vector.y = -vector.y;
		vector.z = -vector.z;

		return vector;
	}

	XMFLOAT3 Normalize(XMFLOAT3 vector)
	{
		RealValue magnitude = VectorMagnitude(vector);

		return DivisionByValue(vector, magnitude);
	}

	XMFLOAT3 ComponentBoundary(XMFLOAT3 vector, float minValue, float maxValue)
	{
		vector = MinComponentValue(vector, minValue);
		vector = MaxComponentValue(vector, maxValue);

		return vector;
	}

	XMFLOAT3 MinComponentValue(XMFLOAT3 vector, float value)
	{
		if (abs(vector.x) < value)
			vector.x = 0.0f;

		if (abs(vector.y) < value)
			vector.y = 0.0f;

		if (abs(vector.z) < value)
			vector.z = 0.0f;

		return vector;
	}

	XMFLOAT3 MaxComponentValue(XMFLOAT3 vector, float value)
	{
		if (abs(vector.x) > value)
			vector.x = value;

		if (abs(vector.y) > value)
			vector.y = value;

		if (abs(vector.z) > value)
			vector.z = value;

		return vector;
	}
}
