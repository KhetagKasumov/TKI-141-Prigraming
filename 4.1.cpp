#include <iostream>
#include <ctime>
#include <random>
#include <cmath>
using namespace std;

/**
* \brief Вводить два числа.
* \param message Побуждающие сообщения для пользователя.
* \return Два числа.
*/
size_t getSize(const string& message);

/**
 * \brief Выбор варианта заполнения массива.
 * \param USER_INPUT Пользователь заполняет массив.
 * \param RANDOM_INPUT Массив заполняется случайными числами.
 */
enum class userInput
{
    USER_INPUT,
    RANDOM_INPUT
};

int* getRandomArray(const size_t size);
int* getUserArray(const size_t size);
void printArray(int* array, const size_t size);
int getIndexOfMaxNegative(int* array, const size_t size);
int getSecondTask(int* array, const size_t size, const int a);
int getThirdTask(int* array, const size_t size, const int a);




/**
* \brief Точка входа в программу.
* \return Возвращает 0 в случае успеха.
*/
int main()
{
    setlocale(LC_ALL, "Rus");

    const size_t size = getSize("Введите размер массива: \n");
    int a = 0;
    cout << "Введите значение А = ";
    cin >> a;

    cout << "Введите число, соответствующее вашему желанию заполнения массива:\n" << "\n"
    << static_cast<int>(userInput::USER_INPUT) << " - вы заполняете массив вручную.\n"
    << static_cast<int>(userInput::RANDOM_INPUT) << " - заполняет массив случайными числами.\n\n";

    int input = 0;
    cin >> input;
    const auto choice = static_cast<userInput>(input);
    cout << "\n";

    int* array = nullptr;

    switch(choice)
    {
        case userInput::USER_INPUT:
        {
            array = getUserArray(size);
            break;
        }
        
        case userInput::RANDOM_INPUT:
        {
            array = getRandomArray(size);
            break;
        }
        
        default:
        {
            cerr << "Введено неверное значение\n";
        }
    }

    cout << "Начальный массив \n";
    printArray(array, size);

    int indexOfMaxNegative = getIndexOfMaxNegative(array, size);
    int temp = array[1];
    array[1] = array[indexOfMaxNegative]; //замена второго элемента на максимальный среди отрицательных

    cout << "\nМассив, второй элемент которого заменен на максимальный среди отрицательных\n";
    printArray(array, size);
    array[1] = temp;

    unsigned int k = getSecondTask(array, size, a);
    cout << "\nКоличество элементов, значения которых положительны и по модулю не превосходят заданное число А = " << k;
    cout << "\n";

    int n = getThirdTask(array, size, a);
    cout << "\nНомер первой пары соседних элементов, сумма которых меньше заданного числа: " << n+1 << " элемент и " << n+2 << " элемент ";



    return 0;
}

size_t getSize(const string& message)
{
    int size = -1;
    cout << message;
    cin >> size;

    if (size < 0)
    {
        throw out_of_range("Incorrect size. Value has to be greater or equal zero.");
    }

    return static_cast<size_t>(size);
}

int* getRandomArray(const size_t size)
{
    const int max = 10;
    const int min = -10;
    //Will be used to obtain a seed for the random number engine
    std::random_device rd;

    //Standard mersenne_twister_engine seeded with rd()
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> uniformIntDistribution(min, max);

    auto* array = new int[size];
    for (size_t index = 0; index < size; index++)
    {
        array[index] = uniformIntDistribution(gen);
    }

    return array;
}

int* getUserArray(const size_t size)
{
    auto* array = new int[size];
    for (size_t i = 0; i < size; i++)
    {
        cin >> array[i]; 
        cout << "\n";
    }

    return array;
}

void printArray(int* array, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        cout << array[i] << "\t";
    }
}

int getIndexOfMaxNegative(int* array, const size_t size)
{
    int max_index = -99999;
    int max = -99999;
    for (size_t i = 0; i < size; i++)
    {
        if ((array[i] < 0) and (array[i] > max))
        {
            max_index = i;
            max = array[i];
        }
    }
    if (max_index != -99999)
    {
        return max_index;
    }
    else 
    {
        return 1;
    }
}

int getSecondTask(int* array, const size_t size, const int a)
{
    unsigned int k = 0;
    for (size_t i = 0; i < size; i++)
    {
        if ((array[i] >= 0) and (abs(array[i]) <= a))
        {
            k += 1;
        }
    }
    return k;
}

int getThirdTask(int* array, const size_t size, const int a)
{
    for (size_t i = 0; i < size-1; i++)
    {
        if ((array[i] + array[i+1]) < a)
        {
            return i;
        }
    }
}