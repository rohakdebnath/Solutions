#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)

void solve()
{
    i64 x, y, z, k; cin >> x >> y >> z >> k;
    i64 mx = 0;
    rep(i, 1, x + 1){
        if (k % i) continue;
        rep(j, 1, y + 1){
            if ((k / i) % j) continue;
            i64 l = k / i / j;
            i64 M = (x - i + 1) * (y - j + 1) * (z - l + 1);
            mx = max(mx, M);
        }
    }
    cout << mx << '\n';
}

int main()
{
    UNSYNC
    i64 T;
    cin >> T;
    while(T--) solve();
    return 0;
}
