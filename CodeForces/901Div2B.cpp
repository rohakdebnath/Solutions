#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define Unsync ios::sync_with_stdio(false); cin.tie(nullptr);
#define sz(x) static_cast<int>((x).size())
#define all(x) x.begin(), x.end()

void solve()
{ 
    i64 n, m, k;
    cin >> n >> m >> k;

    vector<i64> appleJ (n);
    vector<i64> appleG (m);

    for (i64 i {0}; i < n; ++i)
    {
        cin >> appleJ[i];
    }        

    for (i64 i {0}; i < m; ++i)
    {
        cin >> appleG[i];
    }

    if (k == 1)
    {
        if (*min_element(all(appleJ)) < *max_element(all(appleG)))
        {
            swap(*min_element(all(appleJ)), *max_element(all(appleG)));
        }
    }
    
    else if (k == 2)
    {
        if (*min_element(all(appleJ)) < *max_element(all(appleG)))
        {
            swap(*min_element(all(appleJ)), *max_element(all(appleG)));
        }
        if (*min_element(all(appleG)) < *max_element(all(appleJ)))
        {
            swap(*min_element(all(appleG)), *max_element(all(appleJ)));
        }
    }

    else if (k >= 3)
    {
        if (*min_element(all(appleJ)) < *max_element(all(appleG)))
        {
            swap(*min_element(all(appleJ)), *max_element(all(appleG)));
        }
        if (*min_element(all(appleG)) < *max_element(all(appleJ)))
        {
            swap(*min_element(all(appleG)), *max_element(all(appleJ)));
        }

        if (k % 2 == 1)
        {
            swap(*min_element(all(appleJ)), *max_element(all(appleG)));
        }
    }
    i64 sum {accumulate(all(appleJ), 0LL)};
    cout << sum << '\n';
}

int main()
{
    Unsync
    int tests;
    cin >> tests;
    while(tests--)
    {
        solve();
    }

    return 0;
}
