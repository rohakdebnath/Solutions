#include <limits>
#include <vector>
#include <iostream>


void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::vector<int> inputTaker()
{
    std::vector<int> resultVector {};
    int element {};
    while (element != -1)
    {
        std::cin >> element;
        if (!std::cin)
        {
            std::cin.clear();
            ignoreLine();
            continue;
        }
        if (element == -1) continue;

        resultVector.emplace_back(element);
    }
    return resultVector;
    
}

template <typename T>
std::pair<T, T> peakAndTrough(const std::vector<T>& arr)
{
    T min {arr[0]};
    T max {arr[0]};

    for (T i : arr)
    {
        min = std::min(min, i);
        max = std::max(max, i);
    }
    return {min, max};
}

template <typename T>
void printArraywithText(const std::vector<T>& arr)
{
    T minIndex {};
    T maxIndex {};

    std::pair pair {peakAndTrough(arr)};
    
    std::cout << "With array ( ";
    for (int i {0}; i < arr.size(); ++i)
    {
        if (arr[i] == pair.second) maxIndex = i;
        else if (arr[i] == pair.first) minIndex = i;

        if (i == arr.size() - 1) std::cout << arr[i] << " ):\n";
        else std::cout << arr[i] << ", ";
    }

    std::cout << "The min element has index " << minIndex << " and value " << pair.first << '\n';
    std::cout << "The max element has index " << maxIndex << " and value " << pair.second << "\n\n"; 

}

int main()
{
    std::vector vec {inputTaker()};

    printArraywithText(vec);
    return 0;
}
