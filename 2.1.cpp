#include <iostream>

using namespace std;

/**
* \brief Вводит координаты вершин.
* \param message Побуждающие сообщения для пользователя.
* \return Координаты вершин.
*/
double getNumbers(const string& message = "");

/**
* \brief Расчитывает периметр треугольника.
* \param x1 Координата первой вершины треугольника.
* \param y1 Координата первой вершины треугольника.
* \param x2 Координата первой вершины треугольника.
* \param y2 Координата первой вершины треугольника.
* \param x3 Координата первой вершины треугольника.
* \param y3 Координата первой вершины треугольника.
* \rerurn Периметр треугольника.
*/
double getPerimetr(const double x1, const double y1, const double x2, const double y2, const double x3, const double y3);

/**
* \brief Расчитывает площадь треугольника
* \param x1 Координата первой вершины треугольника.
* \param y1 Координата первой вершины треугольника.
* \param x2 Координата первой вершины треугольника.
* \param y2 Координата первой вершины треугольника.
* \param x3 Координата первой вершины треугольника.
* \param y3 Координата первой вершины треугольника.
* \rerurn Площадь треугольника.
*/
double getArea(const double x1, const double y1, const double x2, const double y2, const double x3, const double y, const double half);

/**
* \brief Пользовательский ввод.
* \param PERIMETR Расчет периметра треугольника.
* \param AREA Расчет площади треугольника.
*/
enum class userInput
{
    PERIMETR = 1,
    AREA
};

/**
* \brief Точка входа в программу.
* \return Возращает 0 в случае успеха.
*/
int main()
{
    setlocale(LC_ALL, "Rus");
    const double half = 0.5;
    const double x1 = getNumbers("Введите координаты x1 первой вершины: ");
    const double y1 = getNumbers("Введите координаты y1 первой вершины: ");
    const double x2 = getNumbers("Введите координаты x2 второй вершины: ");
    const double y2 = getNumbers("Введите координаты y2 второй вершины: ");
    const double x3 = getNumbers("Введите координаты x3 третьей вершины: ");
    const double y3 = getNumbers("Введите координаты y3 третьей вершины: ");


    cout << static_cast<int>(userInput::AREA) << " - площадь треугольника \n"
        << static_cast<int>(userInput::PERIMETR) << " - периметр треугольника " << "\n";



    int input = 0;
    cin >> input;
    const auto choice = static_cast<userInput>(input);

    switch (choice)
    {
    case userInput::AREA:
    {
        const auto area = getArea(x1, y1, x2, y2, x3, y3, half);
        cout << "Площадь треугольника = " << area;
        break;
    }
    case userInput::PERIMETR:
    {
        const auto Perimetr = getPerimetr(x1, y1, x2, y2, x3, y3);
        cout << "Периметр треугольника = " << Perimetr;
        break;
    }
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


double getPerimetr(const double x1, const double y1, const double x2, const double y2, const double x3, const double y3)
{
    return sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1))) + sqrt(((x3 - x2) * (x3 - x2)) + ((y3 - y2) * (y3 - y2))) + sqrt(((x1 - x3) * (x1 - x3)) + ((y1 - y3) * (y1 - y3)));
}

double getArea(const double x1, const double y1, const double x2, const double y2, const double x3, const double y3, const double half)
{
    return half * (abs(((x2 - x1) * (y3 - y1)) - ((x3 - x1) * (y2 - y1))));
}
