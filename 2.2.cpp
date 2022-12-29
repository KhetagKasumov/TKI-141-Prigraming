#include <iostream>
using namespace std;

double getNumbers(const string& message);
double getFunctionOne(const double a, const double x);
double getFunctionTwo();
double getFunctionThree(const double a, const double x);

/**
* \brief Точка входа в программу.
* \return Возвращает 0 в случае успеха.
*/
int main()
{
    setlocale(LC_ALL, "Rus");
    const double x = getNumbers("Введите x: ");
    const double a = 1.6;

    if (x > a)
    {
        const double y = getFunctionOne(a, x);
        cout << "y = " << y << "\n";
    }
    else if (x < a)
    {
        const double y = getFunctionThree(a, x);
        cout << "y = " << y << "\n";
    }
    else
    {
        const double y = getFunctionTwo();
        cout << "y = " << y << "\n";
    }
    return 0;
}

double getNumbers(const string& message)
{
    cout << message;
    double numbers = 0.0;
    cin >> numbers;
    return numbers;
}

double getFunctionOne(const double a, const double x)
{
    return exp( a * x) - 2.5;
}

double getFunctionTwo()
{
    return 3;
}

double getFunctionThree(const double a, const double x)
{
    return a / x + sin(x);
}