#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    i64 n, r; cin >> n >> r;
    vector<i64> a (n); for (i64 i = 0; i < n; ++i) cin >> a[i];
    i64 ans = 0, e = 0;
    for (i64 i = 0; i < n; ++i) {
        i64 x = a[i] - a[i] % 2;
        e += a[i] % 2;
        ans += x;
        r -= x / 2;
    }
    cout << ans + min(e, 2 * r - e) << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    i64 T; cin >> T;
    while(T--) solve();
    return 0;
}
