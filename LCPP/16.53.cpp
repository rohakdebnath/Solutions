#include <iostream>
#include <vector>
#include <limits>

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

template <typename T>
void printArray(const std::vector<T>& arr)
{
    for (std::size_t index {0}; index < arr.size(); ++index)
    {
        std::cout << arr[index] << ' ';
    }
    std::cout << '\n';
}

int inputTaker()
{
    while (true)
    {
        int input {};
        std::cout << "Enter a number between 1 and 9: ";
        std::cin >> input;

        if (std::cin.fail())
        {
            if (std::cin.eof()) std::exit(0);
            std::cin.clear();
            ignoreLine();

            continue;
        }
        ignoreLine();
        return input;
    }
}

template <typename T>
int indexAtValue(const std::vector<T>& arr, std::size_t value)
{
    for (std::size_t i {0}; i <= arr.size(); ++i)
    {
        if (arr[i] == value) return i;
    }
    return -1;
}

int main()
{
    std::vector arr{ 4, 6, 7, 3, 8, 2, 1, 9 };

    int value {inputTaker()};
    printArray(arr);

    if (indexAtValue(arr, value) != -1) std::cout << "The number " << value << " has index " << indexAtValue(arr, value) << '\n';
    else std::cout << "The number " << value << " could not be found\n";

    return 0;
}
