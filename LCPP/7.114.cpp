#include <iostream>

void fizzbuzzpop(int limit)
{
    for (int i {1}; i <= limit; ++i)
    {
        bool filled {false};
        if (i % 3 == 0)
        {
            std::cout << "fizz";
            filled = true;
        }
        if (i % 5 == 0) 
        {
            std::cout << "buzz";
            filled = true;
        }
        if (i % 7 == 0) 
        {
            std::cout << "pop";
            filled = true;
        }
        if (!filled) std::cout << i << '\n';
        else std::cout << '\n'; 
    }
}
int main()
{
    fizzbuzzpop(21);
    return 0;
}
