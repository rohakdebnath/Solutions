#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    i64 n, x; cin >> n >> x;
    map<i64, i64> f;
    vector<i64> a (n); for (i64 i = 0; i < n; ++i) cin >> a[i], ++f[a[i]];

    i64 mex = 0;
    while (f[mex]) ++mex;
    for (auto [u, q]: f) {
        if (u > n) break;
        while (f[u] > 1) {
            if ((mex - u) % x == 0 and mex > u) {
                --f[u];
                ++f[mex];
                while (f[mex]) ++mex;
            } else {
                f[u + x] += f[u] - 1;
                f[u] = 1;
            }
        }
    }
    cout << mex << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    i64 T; cin >> T;
    while(T--) solve();
    return 0;
}
