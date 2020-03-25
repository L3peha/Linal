#include <iostream>
#include "../include/Vector.h"

using namespace std;

Vector3D::Vector3D(double _x, double _y, double _z) : x(_x), y(_y), z(_z){}

Vector3D::Vector3D() : Vector3D(0, 0, 0) {}

double Vector3D::getX() const 
{
	return x;
}
double Vector3D::getY() const 
{
	return y;
}
double Vector3D::getZ() const 
{
	return z;
}

void Vector3D::setX(double x) {
	this->x = x;
}
void Vector3D::setY(double y) {
	this->y = y;
}
void Vector3D::setZ(double z) {
	this->z = z;
}

Vector3D Vector3D::operator+ (const Vector3D& v3) const
{
	return Vector3D(x + v3.x, y + v3.y, z + v3.z);
}

double Vector3D::operator* (const Vector3D& v3)
{
	return (x * v3.getX() + y * v3.getY() + z * v3.getZ());
}

Vector3D Vector3D::operator- (const Vector3D& v3) const
{
	return Vector3D(x - v3.x, y - v3.y, z - v3.z);
}

Vector3D Vector3D::operator* (const double a) const
{
	return Vector3D(a * x, a * y, a * z);
}

Vector3D operator* (double a, const Vector3D& v)                //a*vec
{
	return Vector3D(a * v.getX(), a * v.getY(), a * v.getZ());
}

ostream& operator<<(ostream& os, const Vector3D& v)
{
	os << "(" << v.getX() << "; " << v.getY() << "; " << v.getZ() << ")";
	return os;
}

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
}