#include <iostream>
#define _USE_MATH_DEFINES // for C++
#include <cmath>
using namespace std;

/**
 * \brief Считывает число из консоли.
 * \param message Побуждающее сообщение для пользователя.
 * \return Длина окружности.
*/
double getLenght(const string& message);

/**
 * \brief Рассчитывает площадь круга по длине окружности.
 * \param lenght длина окружности.
 * \return Площадь круга.
*/
const double getArea( const double lenght);

/**
* \brief Точка входа в программу.
* \return Возвращает 0 в случае успеха.
*/
int main()
{
    const double lenght = getLenght("Введите длину окружности: ");
    const double area = getArea(lenght);
    cout << "Площадь круга =  " << area << endl;

    return 0;
}


const double getArea(const double lenght)
{
    double radius = (lenght / 2) / M_PI;
    double area = radius * radius * M_PI;
    return area;

}

double getLenght(const string& message)
{
    cout << message;
    double lenght = 0.0;
    cin >> lenght;
    return lenght;
}