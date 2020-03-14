#pragma once
#include <iostream>
#include <string>

using namespace std;

class Vector3D
{
public:
	Vector3D(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {
	}
	Vector3D() : Vector3D(0, 0, 0) {
	}

	//getting coord
	double getX() const {
		return x;
	}
	double getY() const {
		return y;
	}
	double getZ() const {
		return z;
	}
	//coord set

	void setX(double x) {
		this->x = x;
	}
	void setY(double y) {
		this->y = y;
	}
	void setZ(double z) {
		this->z = z;
	}

	//sum
	Vector3D operator+ (const Vector3D& v3) const
	{
		return Vector3D(x + v3.x, y + v3.y, z + v3.z);
	};

	//vec*vec
	double operator* (const Vector3D& v3)
	{
		return (x * v3.getX() + y * v3.getY() + z * v3.getZ());
	};

	//subtraction
	Vector3D operator- (const Vector3D& v3) const
	{
		return Vector3D(x - v3.x, y - v3.y, z - v3.z);
	};

	//vec*a
	Vector3D operator* (const double a) const
	{
		return Vector3D(a * x, a * y, a * z);
	};
protected:
	double x;
	double y;
	double z;
};

//a*vec
Vector3D operator* (double a, const Vector3D& v)
{
	return Vector3D(a * v.getX(), a * v.getY(), a * v.getZ());
};

//output
ostream& operator<<(ostream& os, const Vector3D& v)
{
	os << "(" << v.getX() << "; " << v.getY() << "; " << v.getZ() << ")";
	return os;
};

//input
istream& operator>>(istream& is, Vector3D& v)
{
	double x;
	double y;
	double z;

	is >> x >> y >> z;
	v.setX(x);
	v.setY(y);
	v.setZ(z);
	return is;
};