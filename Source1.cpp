#include <iostream>
#include <cmath>
using namespace std;
/**
*  \brife ������� ������� �� �������� �������.
*  \param x �������� �������.
*  \param y �������� �������.
*  \return �������� �������.
*/
const double getA(const double x, const double y, const double z);
/**
*  \brife ������� ������� �� �������� �������.
*  \param x �������� �������.
*  \param z�������� �������.
*  \return �������� �������.
*/
const double getB(const double x, const double y, const double z);
/**
* \brief ����� ����� � ���������.
* \return ��������� 0 � ������ ������.
*/
int main()
{
	const double x = 1.4;
	const double y = 3.1;
	const double z = 0.5;
	const double a = getA(x, y, z);
	const double b = getB(x, y, z);

	cout << " x = " << x << " y = " << y << " z = " << z << "\n";
	cout << " a = " << a << " b = " << b << endl;
	return 0;
}

const double getA(const double x, const double y, const double z)
{
	return sqrt(z * x * sin(2 * x) + exp(-2 * x) * (x + y));
}

const double getB(const double x, const double y, const double z)
{
	return (exp(2 * x) * log(z + x) - pow(y, 3 * x) * log(y - x));
}