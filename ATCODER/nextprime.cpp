#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(ini, x) for (int i {ini}; i < x; ++i)
#define VI vector<int>
#define VVI vector<vector<int>>

bool isPrime(int n)
{
    bool survive = true;
    for (int i = 2; i*i <= n; ++i)
    {
        if (n % i == 0)
        {
            survive = false;
            break;
        }
    }
    return survive;
}

int main()
{
    UNSYNC
    int X; cin >> X;
    int nextprime;
    while (true)
    {
        if(isPrime(X))
        {
            nextprime = X;
            break;
        }
        else ++X;
    }
    cout << nextprime << '\n';
    return 0;
}
