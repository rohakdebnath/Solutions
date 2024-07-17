#include <bits/stdc++.h>
#define Unsync ios::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

constexpr int limit {5000001};

vector<int> primeFactorCount()
{
    vector<int> smallestFactors (limit);
    vector<int> countPrimeFactors (limit);

    for (int i {2}; i * i <= limit; ++i)
    {
        for (int j {i * i}; j < limit; j += i)
        {
            if (!smallestFactors[j]) smallestFactors[j] = i;
        }
    }

    for (int i {2}; i < limit; ++i)
    {
        if (!smallestFactors[i]) smallestFactors[i] = i;
        countPrimeFactors[i] = countPrimeFactors[i / smallestFactors[i]] + 1;
    }

    for (int i {2}; i < limit; ++i)
    {
        countPrimeFactors[i] += countPrimeFactors[i - 1];
    }
    return countPrimeFactors;

}

void solve(const vector<int>& countPrimeFactors)
{
    int a {}, b {};
    cin >> a >> b;

    cout << countPrimeFactors[a] - countPrimeFactors[b] << '\n';
}

int main()
{
    Unsync
    int tests {};
    cin >> tests;

    vector countPrimeFactors {primeFactorCount()};

    while (tests--)
    {
        solve(countPrimeFactors);
    }

    return 0;
}
