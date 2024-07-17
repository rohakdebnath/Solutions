#include <iostream>
#include <string_view>

enum class Animal
{
    pig,
    chicken,
    goat,
    cat,
    dog,
    duck,
};

constexpr std::string_view getAnimalName(Animal animal)
{
    using enum Animal;
    using namespace std::string_view_literals;

    switch (animal)
    {
        case pig: return "pig"sv;
        case chicken: return "chicken"sv;
        case goat: return "goat"sv;
        case cat: return "cat"sv;
        case dog: return "dog"sv;
        case duck: return "duck"sv;

        default: return "???"sv;
    }
}

int printNumberOfLegs(Animal animal)
{
    using enum Animal;

    switch (animal)
    {
        case duck: 
        case chicken: 
            return 2;
        case pig:
        case goat: 
        case cat:
        case dog:
            return 4;

        default: return -1;
    }

}

int main()
{

    std::cout << "A " << getAnimalName(Animal::cat) << " has " << printNumberOfLegs(Animal::cat) << " legs.\n";
    std::cout << "A " << getAnimalName(Animal::duck) << " has " << printNumberOfLegs(Animal::duck) << " legs.\n";
    return 0;
}
