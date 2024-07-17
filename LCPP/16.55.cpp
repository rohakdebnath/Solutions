#include <iostream>
#include <vector>
#include <cassert>
#include <string_view>

std::string buzzWord(const std::vector<int>& divisors, const std::vector<std::string_view>& words, int n)
{
    std::string mixedWord {};

    for (int i {0}; i <= divisors.size(); ++i)
    {
        if (n % divisors[i] == 0) mixedWord += words[i];
    }

    return mixedWord;
}

int main()
{
    using namespace std::string_view_literals;
    
    std::vector divisors {3, 5, 7, 11, 13, 17, 19};                                         // Maps would be better for this
    std::vector words {"fizz"sv, "buzz"sv, "pop"sv, "bang"sv, "jazz"sv, "pow"sv, "boom"sv}; // Arranged in the corresponding order
    assert(std::size(divisors) == std::size(words) && "array sizes don't match");

    std::cout << "Enter a number: ";
    int n {};
    std::cin >> n;

    for (int i {0}; i <= n; ++i)
    {
        std::string finalWord {buzzWord(divisors, words, i)};
        if (finalWord != "") std::cout << finalWord << '\n';
        else std::cout << i << '\n'; 
    }

    return 0;
}
