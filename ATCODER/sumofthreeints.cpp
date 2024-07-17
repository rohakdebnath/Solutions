#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<i64>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i {ini}; i < x; ++i)
#define per(i, fin, x) for (i64 i {fin}; i >= x; --i)
#define VI vector<i64>
#define VVI vector<vector<i64>>

int main()
{
    UNSYNC
    i64 K, S; cin >> K >> S;
    i64 ans = 0;
    rep(X, 0, K + 1)
    {
        rep(Y, 0, K + 1)
        {
            i64 Z = S - X - Y;
            if (Z >= 0 and Z <= K) ++ans;
        }
    }
    cout << ans << '\n';
    return 0;
}
