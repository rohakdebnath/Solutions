#include <bits/stdc++.h>

struct Fraction
{
    int numerator {};
    int denominator {1};
};

Fraction fractionReader()
{
    Fraction temp {};
    std::cout << "Enter a value for the numerator: ";
    std::cin >> temp.numerator;
    std::cout << "Enter a value for the denominator: ";
    std::cin >> temp.denominator;

    return temp;
}

Fraction multiplyFractions(const Fraction& first, const Fraction& second)
{
    return {first.numerator * second.numerator, first.denominator * second.denominator};
}

void printFraction(const Fraction& fraction)
{
    std::cout << fraction.numerator << "/" << fraction.denominator;
}

int main()
{
    Fraction fraction1 {fractionReader()};
    Fraction fraction2 {fractionReader()};

    std::cout <<  "Your fractions multiplied together: ";
    printFraction(multiplyFractions(fraction1, fraction2));
    std::cout << '\n';

    return 0;
}
