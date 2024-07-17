#include <iostream>
int sumTo(int limit)
{
    int sum {0};
    for (int i {1}; i <= limit; ++i)
    {
        sum+=i;
    }
    return sum;
}

int main()
{
    std::cout << sumTo(15) << '\n';
    return 0;
}
