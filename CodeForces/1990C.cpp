#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    i64 n; cin >> n;
    vector<i64> a (n); for (i64 i = 0; i < n; ++i) cin >> a[i];
    i64 ans = accumulate(a.begin(), a.end(), 0LL);
    vector<i64> f (n + 1);
    i64 m = 0;
    for (i64 i = 0; i < n; ++i) {
        ++f[a[i]];
        m = max(m, f[a[i]] > 1 ? a[i] : 0);
        a[i] = m;
    }
    f = vector<i64> (n + 1, 0);
    for (i64 i = 0; i < n; ++i) {
        ++f[a[i]];
    }
    i64 l = 0;
    for (i64 i = 0; i < n; ++i) {
        if (f[a[i]] > 1) {
            ans += a[i] * (n - i);
            l = a[i];
        } else {
            ans += a[i] + max<i64>(n - i - 1, 0) * l;
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
