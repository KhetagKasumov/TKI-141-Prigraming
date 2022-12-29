#include <iostream>
using namespace std;

double getHeight(const string& message);
double getPressure(double h);

/**
* \brief Точка входа в программу.
* \return Возвращает 0 в случае успеха.
*/
int main()
{   
    double h = getHeight("Введите высоту столба: ");
    double p = getPressure(h);
    cout << "Давление воды на дно цистерны при высоте " << h << " метров" << " = " << p << " Паскалей" << endl;
    return 0;
}

double getHeight(const string& message)
{
    double height = -1;
    cout << message;
    cin >> height;

    if (height < 0)
    {
        throw out_of_range("Incorrect size. Value has to be greater or equal zero.");
    }

    return height;
}

double getPressure(double h)
{
    double p = 1000 * 9.8 * h;
    return p;
}