#include <iostream>
#include <cmath>
using namespace std;

/**
*  \brife Функция расчкта по заданной формуле.
*  \param x Аргумент функции.
*  \param y Аргумент функции.
*  \return Звнчение функции.
*/
const double getA(const double x, const double y, const double z);

/**
*  \brife Функция расчкта по заданной формуле.
*  \param x Аргумент функции.
*  \param z Аргумент функции.
*  \return Значение функции.
*/
const double getB(const double x, const double y, const double z);

/**
* \brief Точка входа в программу.
* \return Возращает 0 в случае успеха.
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
