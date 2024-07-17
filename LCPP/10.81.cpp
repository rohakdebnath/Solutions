#include <bits/stdc++.h>

struct Adstats
{
    int adsWatched {};
    double clickPercentage {};
    double avgEarning {};
};

Adstats dataCollector(Adstats& youEarningsData)
{

    std::cout << "How many customers watched your ad?: ";
    std::cin >> youEarningsData.adsWatched;
    std::cout << "Percentage of people who clicked on your ad?: ";
    std::cin >> youEarningsData.clickPercentage;
    std::cout << "Average earning per ad?: ";
    std::cin >> youEarningsData.avgEarning;

    return youEarningsData;
}

void printAdRevenue(const Adstats& data)
{
    std::cout << "Your net earnings: " << data.adsWatched * data.avgEarning * data.clickPercentage / 100 << '\n';
}

int main()
{
    Adstats myEarningsData {};
    dataCollector(myEarningsData);
    printAdRevenue(myEarningsData);
}

