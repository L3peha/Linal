#pragma once
#ifndef MATRIX_H
#define MATRRIX_H

#include <iostream>
#include "Vector.h"

using namespace std;


class Matrix3D  
{
public:
	Matrix3D();
	Matrix3D(double ne[9]);
	~Matrix3D();

	double get(int i, int j) const;
	void set(int i, int j, double data);

	Matrix3D operator+ (const Matrix3D& m3) const;
	Matrix3D operator- (const Matrix3D& m3) const;
	Matrix3D operator* (const double a) const;
	Matrix3D operator*(const Matrix3D m3) const;
	Vector3D operator* (const Vector3D v3) const;
	
	double det();

protected:
	double matrix[3][3];
};

Matrix3D operator* (const double a, const Matrix3D& m3);

istream& operator>>(istream& is, Matrix3D& m3);
ostream& operator<<(ostream& os, const Matrix3D& m3);
#endif // !MATRIX_H