#pragma once
#ifndef VECTOR_H
#define VECTOR_H


#include <iostream>
#include <string>

using namespace std;

class Vector3D
{
public:
	Vector3D(double _x, double _y, double _z);
	Vector3D();

	double getX() const;
	double getY() const;
	double getZ() const;

	void setX(double x); 
	void setY(double y); 
	void setZ(double z);

	Vector3D operator+ (const Vector3D& v3) const;
	double operator* (const Vector3D& v3);
	Vector3D operator- (const Vector3D& v3) const;
    Vector3D operator* (const double a) const;
protected:
	double x;
	double y;
	double z;
};

Vector3D operator* (double a, const Vector3D& v);

ostream& operator<<(ostream& os, const Vector3D& v);
istream& operator>>(istream& is, Vector3D& v);
#endif // !VECTOR_H