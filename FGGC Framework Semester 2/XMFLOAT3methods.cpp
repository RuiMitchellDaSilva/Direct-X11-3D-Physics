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

	float VectorMagnitude(XMFLOAT3 vector)
	{
		return sqrtf((vector.x * vector.x) + (vector.y * vector.y) + (vector.z * vector.z));
	}
}