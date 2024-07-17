#include <iostream>

bool isEven(int num)
{
    if (num % 2 !=0)
        return false;
    else
        return true;
}

int getInput()
{
    std::cout << "Enter an integer: ";
    int num {};
    std::cin >> num;

    return num;
}

int main()
{
    int num {getInput()};
    if (isEven(num))
        std::cout << num << " is even\n";
    else 
        std::cout << num << " is odd";

}
