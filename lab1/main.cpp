#include <iostream>

void fillArray(double* array, int size)
{
    std::cout << "Enter the first element of array: \n";
    std::cin >> array[0];
    for (int i = 1; i < size; ++i)
        array[i] = array[i - 1] + 6.3;
}

void printArray(const double* array, int size)
{
    for (int i = 0; i < size; ++i)
        std::cout << "X[" << i << "] = " << array[i] << '\n';
}

void printFunctionResult(const double* array, int size)
{
    for (int i = 0; i < size; ++i) {
        double result;
        double x = array[i];
        if (x > 0) {
            result = x * x + 3 * x + 8;
        } else if (x >= 15 && x <= 50) {
            result = (x - 10) / 6;
        } else {
            result = (7 / 8) * x;
        }
        std::cout << std::fixed << "F(" << x << ") = ";
        std::cout << std::scientific << result << '\n';
    }
}

int main()
{
    const int SIZE = 8;
    double array[SIZE];
    fillArray(array, SIZE);
    std::cout << std::endl;
    printArray(array, SIZE);
    std::cout << std::endl;
    printFunctionResult(array, SIZE);
    std::cout << std::endl;

    return 0;
}
