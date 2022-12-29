#include <limits>
/**
* \brief ������������ ������� ������������
*
*/
#include <iostream>

using namespace std;

/**
* \brief ���������� �� ������� � ����� x.
* \param x �������� �������.
* \return true, ���� ����������.
*/
bool IsExists(const double x);

/**
* \brief ������ ������� � ����� x.
* \param x �������� �������.
* \return �������� ������� � ����� x.
*/
double Calculation(const double x);

/**
* \brief ����� ����� � ���������.
* \return ���������� 0 � ������ ������.
*/
int main()
{
	const double xStart = 1;
	const double xFinish = 3;
	const double step = 0.2;
	double x = xStart;
	while (x < xFinish + step)
	{
		if (IsExists(x))
		{
			const double y = Calculation(x);
			cout << x << " " << y << "\n";
		}
		else
		{
			cout << x << " " << "��� �������� \n"; 
		}

		x = x + step;
	}
	return 0;
}

bool IsExists(const double x)
{
	return (abs(exp(x)) > DBL_MIN);
}

double Calculation(const double x)
{
	return 3 * x - 14 + exp(x) - exp(-x);
}