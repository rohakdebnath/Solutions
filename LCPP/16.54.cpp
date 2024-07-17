#include <iostream>
#include <vector>

template <typename T>
T findMax(const std::vector<T>& arr)
{
    T currentMax {};
    for (int i {0}; i <= arr.size(); ++i)
    {
        if (arr[i] >= currentMax) currentMax = arr[i];
        
    }
    return currentMax;
}

int main()
{
    std::vector testScore { 84, 92, 76, 81, 56 };
    std::cout << "The max score is: " << findMax(testScore) << '\n'; // prints 92

    return 0;
}
