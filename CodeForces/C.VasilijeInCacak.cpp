#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define Unsync ios::sync_with_stdio(false); cin.tie(nullptr);
#define sz(x) static_cast<ll>((x).size())
#define all(x) x.begin(), x.end()

void solve()
{
    ll n, k, x;
    cin >> n >> k >> x;
    
    ll min {0}, max {0};

    min = k*(k+1)/2;
    max= n*(n+1)/2 - (n-k)*(n-k+1)/2;

    if ( x >= min and x <= max) cout << "YES\n";
    else cout << "NO\n";
    
}

int main()
{
    Unsync
    ll tests;
    cin >> tests;

    while (tests--)
    {
        solve();
    }
    return 0;
}
