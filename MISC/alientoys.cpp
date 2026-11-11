#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

mt19937 rng((i64) std::chrono::steady_clock::now().time_since_epoch().count());
i64 rnd(i64 x, i64 y) {
    return uniform_int_distribution<i64>(x, y)(rng);
}
const i64 inf = 1e18;
const i64 mod = 1e9 + 7;
void solve() {
    string a, b; cin >> a >> b;
    i64 n = a.size(), m = b.size();
    vector<i64> f (26);
    for (i64 i = 0; i < 26; ++i) {
        f[i] = rnd(0, inf);
    }
    i64 ss = 0, st = 0;
    for (i64 i = 0; i < m; ++i) {
        ss = (ss + f[b[i] - 'a']) % mod;
        st = (st + f[a[i] - 'a']) % mod;
    }
    vector<i64> ans;
    for (i64 i = 0; i + m < n; ++i) {
        if (ss == st) ans.push_back(i);
        st = ((st - f[a[i] - 'a'] + f[a[i + m] - 'a']) % mod + mod) % mod;
    }
    if (ss == st) ans.push_back(n - m);
    cout << ans.size() << '\n';
    for (i64 i = 0; i < ans.size(); ++i) {
        cout << ans[i] + 1 << " \n"[i == ans.size() - 1];
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
