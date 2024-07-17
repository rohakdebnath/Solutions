#include <iostream>

double getInput()
{
    std::cout << "Enter a double value: ";
    double x {};
    std::cin >> x;
    
    return x;
}

char getOperatedResult()
{
    std::cout << "Enter one of the following: +, -, *, or /: ";
    char symbol {};
    std::cin >> symbol;

    return symbol;
}

void printAnswer(double x, double y)
{
    char symbol {getOperatedResult()};
    double answer {};

    if (symbol == '+')
        answer = x + y;
    else if (symbol == '-')
        answer = x - y;
    else if (symbol == '*')
        answer = x * y;
    else if (symbol == '/')
        answer = x / y;

    std::cout << x << " " << symbol << " " << y << " is " << answer << '\n';

}

int main()
{
    double x {getInput()};
    double y {getInput()};
    printAnswer(x, y);
}
