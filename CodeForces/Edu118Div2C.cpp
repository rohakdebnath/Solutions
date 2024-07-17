//Inspired by Jiangly's coding style

#include <bits/stdc++.h>
using ll = long long;

void cases()
{
    int hits {};
    ll health {};
    std::cin >> hits >> health;

    std::vector<ll> a(hits);
    for (int i{0}; i < hits; ++i)
    {
        std::cin >> a[i];
    }

    ll left {1}, right {health};

    while (left < right)
    {
        ll minPD = (left + right) / 2;
        ll damage {0};

        for (ll i {0}; i < hits - 1; ++i)
        {
            damage += std::min(a[i + 1] - a[i], minPD);
        }
        damage += minPD;                                 //for last hit

        if (damage >= health) right = minPD;
        else left = minPD + 1;
    }

    std::cout << left << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int testCases {};
    std::cin >> testCases;

    while (testCases--)
    {
        cases();
    }

    return 0;
}
