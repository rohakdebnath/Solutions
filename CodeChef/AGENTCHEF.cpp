#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define Unsync ios::sync_with_stdio(false); cin.tie(nullptr);
#define sz(x) static_cast<int>((x).size())
#define all(x) x.begin(), x.end()

void solve()
{
    int x;
    cin >> x;
    if (500 % x == 0) cout << 500 / x << '\n';
    else cout << 500/x + 1 << '\n'; 
}

int main()
{
    Unsync
    int tests;
    cin >> tests;

    while (tests--)
    {
        solve();
    }
    return 0;
}
