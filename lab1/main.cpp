//ВАРИАНТ 13

#include <iomanip>
#include <iostream>

double randomNumber(double min, double max)
{
    return min + (rand() % (int)(max - min + 1));
}

void inputArray(double* array, int size)
{
    for (int i = 0; i < size; ++i)
        std::cin >> array[i];
}

void fillArrayByFirst(double* array, int size)
{
    std::cin >> array[0];
    for (int i = 1; i < size; ++i)
        array[i] = array[i - 1] + 6.3;
}

void printArray(const double* array, int size,
                const char* arrayName = "Array",
                int precision = 5)
{
    std::cout << std::setprecision(precision);
    for (int i = 0; i < size; ++i)
        std::cout << arrayName << i + 1 << "\t" << array[i] << '\n';
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
        result = 3 * (x * x) + 3 * x + 8;
    } else if (x >= 0 && x < 20) {
        result = -(5 / (x - 8));
    } else {
        result = 4 * (x + 8);
    }

    return result;
}

void fillArrayRandom(double* array, int size, double min, double max)
{
    for (int i = 0; i < size; ++i)
        array[i] = randomNumber(min, max);
}

int main()
{
    const int XY_SIZE = 8;
    const int X1_MAX_SIZE = 15;
    double x[XY_SIZE];
    double x1[X1_MAX_SIZE];
    double y[XY_SIZE];

    std::cout << "Enter the first element of array: \n";
    fillArrayByFirst(x, XY_SIZE);
    std::cout << std::endl;
    std::cout << "Elements of X: \n";
    printArray(x, XY_SIZE, "x");
    std::cout << std::endl;
    std::cout << "Average of X elements: ";
    std::cout << std::scientific << averageArray(x, XY_SIZE) << '\n';

    for (int i = 0; i < XY_SIZE; ++i)
        y[i] = calculateFunction(x[i]);
    std::cout << std::fixed;
    printArray(y, XY_SIZE, "y", 3);

    int x1Size;
    std::cin >> x1Size;
    while (x1Size < 10 || x1Size > 15) {
        std::cout << "Size of the array out of bounds! Please, try again\n";
        std::cin >> x1Size;
    }
    srand(time(0));
    fillArrayRandom(x1, x1Size, 99, 100);
    printArray(x1, x1Size, "x1_", 3);

    std::cout << "Average of X elements: ";
    std::cout << std::scientific << averageArray(x1, x1Size) << '\n';

    return 0;
}
