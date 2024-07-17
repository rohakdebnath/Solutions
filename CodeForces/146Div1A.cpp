#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define Unsync ios::sync_with_stdio(false); cin.tie(nullptr);
#define v(x) vector<x>;
#define sz(x) static_cast<int>((x).size())
#define all(x) x.begin(), x.end()

bool isCoprime(ll p, ll q)
{
    ll minVal = min(p, q);
    for (ll i {2}; i <= minVal; ++i)
    {
        if (p % i == 0 and q % i == 0) return true;
    }
    return false;
}

int main()
{
    Unsync
    ll n;
    cin >> n;

    ll ans {};
    if (n == 1) ans = 1;
    else if (n == 2) ans = 2;
    else if (n % 2 == 0) 
    {
        if (isCoprime(n, n - 3)) ans = (n - 1) * (n - 2) * (n - 3);
        else ans = (n) * (n - 1) * (n - 3);
    }
    else ans = n * (n - 1) * (n - 2);

    cout << ans << '\n';

    return 0;
}
