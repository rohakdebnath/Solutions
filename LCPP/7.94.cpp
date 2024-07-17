#include <iostream>
void symbolPadder(char c, int tempInt)
{
    while (5 - tempInt > 0)
    {
    std::cout << c << ' ';
    ++tempInt;
    }
}

int main()
{  
    int outer {1};
    while (outer <= 5)
    {
        int inner {outer};
        symbolPadder(' ', inner);
        while (inner >= 1)
        {
            std::cout << inner-- << ' ';
        }
        std::cout << '\n';
        ++outer;
    }
    return 0;
}
