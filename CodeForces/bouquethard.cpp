#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    i64 n, m; cin >> n >> m;
    vector<i64> a (n); for (i64 i = 0; i < n; ++i) cin >> a[i];
    vector<i64> c (n); for (i64 i = 0; i < n; ++i) cin >> c[i];
    vector<i64> id (n);
    iota(id.begin(), id.end(), 0);
    sort(id.begin(), id.end(), [&] (i64 i, i64 j) {return a[i] < a[j];});
    sort(a.begin(), a.end());
    vector<i64> b (n);
    for (i64 i = 0; i < n; ++i) {
        b[i] = c[id[i]];
    }
    auto check = [&] (i64 x, i64 f1, i64 f2) -> i64{
        i64 q = min(m / x, f1);
        f1 -= q;
        i64 r = m - q * x;
        i64 s = min(r / (x + 1), f2);
        f2 -= s;
        r -= (x + 1) * s;

        return q * x + s * (x + 1) + min({r, f2, q});
    };
    i64 ans = 0;
    for (i64 i = 0; i < n; ++i) {
        if (1 + a[i] == a[i + 1] and i + 1 < n) {
            ans = max(ans, check(a[i], b[i], b[i + 1]));
        } else {
            i64 q = min(m / a[i], b[i]);
            ans = max(ans, a[i] * q);
        }
    }
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    i64 T; cin >> T;
    while(T--) solve();
    return 0;
}
