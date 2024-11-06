//ВАРИАНТ 13

#include <iomanip>
#include <iostream>
#include <windows.h>

#define DEFAULT_PRESCISION 6

double randomNumber(double min, double max)
{
    return (double)rand() / RAND_MAX * (max - min) + min;
}

void inputArray(double* array, int size)
{
    for (int i = 0; i < size; ++i)
        std::cin >> array[i];
}

void fillArithmProgression(double* array, int size, double first, double step)
{
    array[0] = first;
    for (int i = 1; i < size; ++i)
        array[i] = array[i - 1] + step;
}

void printArray(const double* array,
                int size,
                const char* arrayName = "Array",
                bool exponential = false,
                int precision = DEFAULT_PRESCISION)
{
    if (exponential)
        std::cout << std::scientific;
    std::cout << std::setprecision(precision);

    for (int i = 0; i < size; ++i)
        std::cout << arrayName << i + 1 << "\t" << array[i] << '\n';

    if (exponential)
        std::cout << std::fixed;
    std::cout << std::setprecision(DEFAULT_PRESCISION);
}

double averageArray(const double* array, int size)
{
    double result = 0;
    for (int i = 0; i < size; ++i) {
        result += array[i];
    }
    result /= size;
    return result;
}

double calculateFunction(double x)
{
    double result;
    if (x < 0) {
        result = 3.0 * (x * x) + 3.0 * x + 8.0;
    }
    else if (x >= 0 && x < 20) {
        result = -(5.0 / (x - 8.0));
    }
    else {
        result = 4.0 * (x + 8.0);
    }

    return result;
}

void fillArrayRandom(double* array, int size, double min, double max)
{
    srand(time(0));
    for (int i = 0; i < size; ++i)
        array[i] = randomNumber(min, max);
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int XY_SIZE = 8;
    const int X1_MAX_SIZE = 15;
    double x[XY_SIZE];
    double x1[X1_MAX_SIZE];
    double y[XY_SIZE];

    std::cout << "Введите первый элемент массива: ";
    double first;
    std::cin >> first;
    fillArithmProgression(x, XY_SIZE, first, 6.3);
    std::cout << "Элементы массива X: ";
    printArray(x, XY_SIZE, "x");

    printf("Среднее значение элементов массива X: %e\n\n", averageArray(x, XY_SIZE));

    for (int i = 0; i < XY_SIZE; ++i)
        y[i] = calculateFunction(x[i]);
    std::cout << "Элементы массива Y, рассчитанные по функции F(Xi):\n";
    printArray(y, XY_SIZE, "y", false, 3);

    std::cout << "\nВведите количество элементов в массиве X1: ";
    int x1Size;
    std::cin >> x1Size;
    while (x1Size < 10 || x1Size > 15) {
        std::cout << "Размер массива не может быть больше 15 или меньше 10. Попробуйте еще раз.";
        std::cin >> x1Size;
    }

    std::cout << "Введите минимальное и максимальное число для заполнения массива случайными значениями.\n";
    int min, max;
    std::cout << "Минимальное: ";
    std::cin >> min;
    std::cout << "Максимальное: ";
    std::cin >> max;
    fillArrayRandom(x1, x1Size, min, max);
    printArray(x1, x1Size, "x1_");

    printf("Среднее значение элементов массива X1: %e\n", averageArray(x1, x1Size));

    return 0;
}
