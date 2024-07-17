#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, m, d; cin >> n >> m >> d;
    vector<int> s (m); for (int i = 0; i < m; ++i) cin >> s[i];
    vector<i64> p (m + 1); p[0] = 1;
    for (int i = 0; i < m; ++i) {
        p[i + 1] = p[i] + (s[i] - (i - 1 >= 0 ? s[i - 1] : 1) - 1) / d + 1 - ((s[i] - (i - 1 >= 0 ? s[i - 1] : 1) - 1) < 0);
    }
    map<i64, i64> f;
    for (int i = 0; i < m; ++i) {
        i64 t = (i + 2 <= m ? p[m] - p[i + 2] + 1: 0) + p[i] + ((i + 1 < m ? s[i + 1] : n + 1) - (i - 1 >= 0 ? s[i - 1] : 1) - 1) / d + (i != m - 1 ? (n - s[m - 1]) / d : 0);
        ++f[t];
    }
    auto u = f.begin();
    cout << (u ->first) << ' ' << (u ->second) << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
