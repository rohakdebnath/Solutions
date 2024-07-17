#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<i64>(x)
#define all(x) x.begin(), x.end()
#define rep(ini, x) for (i64 i {ini}; i < x; ++i)
#define VI vector<i64>
#define VVI vector<vector<i64>>
i64 gcd(i64 a, i64 b) {return b > 0 ? gcd(b, a % b) : a;}

void solve()
{
    i64 n; cin >> n;
    VI a (n); rep(0, n) cin >> a[i];
    i64 moves = 0;
    if (n == 1)
    {
        cout << 1 << '\n';
        return;
    }
    int g = 0;
    rep(1, n) g = gcd(g, a[i] - a[i - 1]);
    sort(all(a));
    rep(0, n) moves += (a[n - 1] - a[i])/g;
    for(int i = 1;; ++i)
    {
        if (!binary_search(all(a), a[n - 1] - g*i))
        {
            moves += i;
            break;
        }
    }
    cout << moves << '\n';
}

int main()
{
    UNSYNC
    i64 T;
    cin >> T;
    while(T--) solve();
    return 0;
}
