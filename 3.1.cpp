#include <limits>
/**
* \brief Рассчитывает площадь треугольника
*
*/
#include <iostream>

using namespace std;

/**
* \brief Существует ли функция в точке x.
* \param x Аргумент функции.
* \return true, если существует.
*/
bool IsExists(const double x);

/**
* \brief Расчет функции в точке x.
* \param x Аргумент функции.
* \return Значение функции в точке x.
*/
double Calculation(const double x);

/**
* \brief Точка входа в программу.
* \return Возвращает 0 в случае успеха.
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
			cout << x << " " << "Нет значения \n"; 
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