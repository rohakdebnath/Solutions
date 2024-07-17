#include "16.x5.h"
#include <iostream>
#include <vector>
#include <limits>

constexpr int totalAttempts {6};

struct Session
{
    std::string word {};
    std::string underscoredWord {};
    std::string wrongGuessString {};
    std::string wrongPlus = std::string(totalAttempts, '+');
    
};

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool isItAlreadyAttempted(const Session& session, char c)
{
    for (char i : session.underscoredWord)
    {
        if (i == c and i != '_') return true;
    }
    for (char i : session.wrongGuessString)
    {
        if (i == c and i != '+') return true;
    }
    return false;
}

void printState(const Session& session)
{
    std::cout << "The word: " << session.underscoredWord << '\t' << "Wrong guesses: " << session.wrongPlus << '\n';
}

void getAttempts(Session& session)
{
    char c {};
    while (true)
    {
        std::cout << "Enter your next letter: ";
        std::cin >> c;
        if (c < 'a' or c > 'z')
        {
            if (std::cin.eof()) std::exit(0);
            std::cin.clear();
            std::cout << "That wasn't a valid input.  Try again.\n\n";
            printState(session);
            ignoreLine();
            continue;
        }
        else 
        {
            ignoreLine();
            break;
        }
    }
    
    if (std::find(session.word.begin(), session.word.end(), c) != session.word.end() and !isItAlreadyAttempted(session, c)) //letter found and not attempted before
    {
        std::cout << "Yes, " << c << " is in the word!\n\n";

        for (int i {0}; i <= session.word.size(); ++i)
        {
            if (session.word[i] == c) session.underscoredWord[i] = c;
        }
    }
    else if (isItAlreadyAttempted(session, c))
    {
        std::cout << "You already guessed that.  Try again.\n\n";
    }
    else
    {
        session.wrongGuessString += c;
        session.wrongPlus = std::string(totalAttempts - session.wrongGuessString.size(), '+') + session.wrongGuessString;

        std::cout << "No, " << c << " is not in the word!\n\n";
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

namespace WorldList
{
    std::vector<std::string> list {"broccoli", "mystery", "account", "almost", "spaghetti", "opinion", "beautiful", "distance", "luggage"};
}

int main()
{
    std::cout << "Welcome to C++man (a variant of Hangman)\nTo win: guess the word.  To lose: run out of plusses.\n\n";

    do
    {
        Session session {};
        session.word = {WorldList::list[Random::get(0, WorldList::list.size() - 1)]};
        session.underscoredWord = std::string(session.word.size(), '_');
        do
        {
            printState(session);
            getAttempts(session);
            if (session.underscoredWord == session.word)
            {
            printState(session);
                std::cout << "Congratulations! You guessed it!\n\n"; 
                break;
            }
            if (session.wrongPlus.find('+') == std::string::npos)
            {
                printState(session);
                std::cout << "You lost!  The word was: " << session.word << "\n\n";
                break;
            }
        } 
        while (true);
        }
    while (playAgain());

    return 0;
}
