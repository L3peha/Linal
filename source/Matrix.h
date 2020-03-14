#pragma once
#include <iostream>
#include "Vector.h"

using namespace std;


class Matrix3D     //:public Vector3D maybe one day i will do it
{
public:
	Matrix3D() {
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				matrix[i][j] = 0;
	}
	Matrix3D(double ne[9]) {
		int k = 0;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				matrix[i][j] = ne[k++];

	}
	~Matrix3D(){}

	double get(int i, int j) const
	{
		return matrix[i][j];
	}

	void set(int i, int j, double data)
	{
		this->matrix[i][j] = data;
	}

	//sum
	Matrix3D operator+ (const Matrix3D& m3) const
	{
		Matrix3D temp;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				temp.set(i, j, this->get(i, j) + m3.get(i, j));
		return temp;
	}
    //subtraction
	Matrix3D operator- (const Matrix3D& m3) const
	{
		Matrix3D temp;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				temp.set(i, j, this->get(i, j) - m3.get(i, j));
		return temp;
	}
	//matrix*a
	Matrix3D operator* (const double a) const
	{
		Matrix3D temp;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				temp.set(i, j, a * this->get(i, j));
		return temp;
	}

	//determinant
	double det()
	{
		double a = 1, b = 1, c = 1, d = 1, e = 1, f = 1;
		for (int i = 0; i < 3; i++)
		{
			a *= this->get(i, i);
			if (i != 2)                                                // (0;0) (0;1) (0;2)
			{                                                          // (1;0) (1;1) (1;2)
				b *= this->get(i, i + 1);                              // (2;0) (2;1) (2;2)
				c *= this->get(i+1, i );
			}
			else
			{
				b *= this->get(i, 0);
				c *= this->get(0, i);
			}
		}
		for (int i = 0; i < 3; i++)
		{
			d *= this->get(i, 2 - i);
			if (i != 2)
			{
				e *= this->get(i, 1 - i);
				f *= this->get(i, i * 2);
			}
			else
			{
				f *= this->get(2, 1);
				e *= this->get(i, 2);
			}
		}
		//cout << a << " " << b << " " << c << " " << d << " " << e << " " << f << " ";
		return (a + b + c - d - e - f);
	}

	//martix*matrix
	Matrix3D operator*(const Matrix3D m3) const
	{
		Matrix3D temp;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				double sum = 0;
				for (int k = 0; k < 3; k++)
				{
					sum += this->get(i, k) * m3.get(k, j);
				}
				temp.set(i, j, sum);
			}
		}
		return temp;
	}

	//matrix*vector
	Vector3D operator* (const Vector3D v3) const
	{
		Vector3D temp;
		temp.setX(this->get(0, 0) * v3.getX() + this->get(0, 1) * v3.getY() + this->get(0, 2) * v3.getZ());
		temp.setY(this->get(1, 0) * v3.getX() + this->get(1, 1) * v3.getY() + this->get(1, 2) * v3.getZ());
		temp.setZ(this->get(2, 0) * v3.getX() + this->get(2, 1) * v3.getY() + this->get(2, 2) * v3.getZ());
		return temp;
	}
protected:
	double matrix[3][3];
};

//a*matrix
Matrix3D operator* (const double a, const Matrix3D& m3)
{
	Matrix3D temp;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			temp.set(i, j, a * m3.get(i, j));
	return temp;
}

//output
ostream& operator<<(ostream& os, const Matrix3D& m3)
{
	os << endl;
	for (int i = 0; i < 3; i++) {
		os << "||";
		for (int j = 0; j < 3; j++)
			os << m3.get(i, j) << " ";
		os <<"||"<< endl;
	}
	os << "------------------------------------------------------------"<<endl;
	return os;
}

//input
istream& operator>>(istream& is, Matrix3D& m3)
{
	double temp[3][3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
		{
			is >> temp[i][j];
			m3.set(i, j, temp[i][j]);
		}
	}
	return is;
}