#include <iostream>
#include "7.x4.h"


int thinkOfANumber()
{
    int correctGuess {Random::get(1, 100)};
    return correctGuess;
}

void guessTaker(int correctGuess, int guesses)
{
    int count {1};
    while (true)
    {
        if (count > guesses)
        {
            std::cout << "Sorry, you lose. The correct number was " << correctGuess << ".\n";
            return;
        }
        std::cout << "Guess #" << count << ": ";
        int userGuess {};
        std::cin >> userGuess;

        if (std::cin.fail())
        {
            if (std::cin.eof()) std::exit(0);
            std::cin.clear();
            ignoreLine();
            continue;
        }
        if (userGuess < 1 or userGuess >100)
        {
            ignoreLine();
            continue;
        } 

        ignoreLine();

        if (userGuess > correctGuess) std::cout << "Your guess is too high.\n"; 
        else if (userGuess < correctGuess) std::cout << "Your guess is too low.\n";
        else
        {
            std::cout << "Correct! You win!\n";
            return; 
        }
        ++count;

    }
}

bool playAgain()
{
    while (true)
    {
        std::cout << "Would you like to play again (y/n)? ";
        char valid {};
        std::cin >> valid;

        if (std::cin.fail())
        {
            if (std::cin.eof()) std::exit(0);
            std::cin.clear();
        }
        ignoreLine();

        switch (valid)
        {
            case 'y': return true;
            case 'n': return false;
        }
    }
}
int main()
{
    constexpr int guesses {7};
    do
    {
        std::cout << "Let's play a game. I'm thinking of a number between 1 and 100. You have " << guesses << " tries to guess what it is.\n";
        guessTaker(thinkOfANumber(), guesses);
    }
    while (playAgain());
    
    std::cout << "Thank you for playing.\n";
    return 0;
}
