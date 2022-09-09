#pragma once
#include <numbers>
#include <cmath>

struct Vector3
{
	 
	Vector3(
		double x = 0.f,
		double y = 0.f,
		double z = 0.f) :
		x(x), y(y), z(z) { }

	Vector3 toAngle()
	{
		return Vector3{
			std::atan2(-z, std::hypot(x, y)) * (180.0f / std::numbers::pi_v<double>),
			std::atan2(y, x) * (180.0f / std::numbers::pi_v<double>),
			0.0f };
	}
	Vector3 operator/(double divisor)
	{
		 return Vector3{ x / divisor, y / divisor, z / divisor };
	}

	Vector3 operator*(double multiplier)
	{
		 return Vector3{ x * multiplier, y * multiplier, z * multiplier };
	}
	Vector3 operator-(Vector3& subtrahend)
	{
		return Vector3{ x - subtrahend.x, y - subtrahend.y, z - subtrahend.z };
	}
	Vector3 operator+(Vector3& addend)
	{
		return Vector3{ x + addend.x, y + addend.y, z + addend.z };
	}

	
	double x, y, z;
};
