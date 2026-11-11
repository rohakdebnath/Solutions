#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    i64 n, m; cin >> n >> m;
    vector<i64> a (n); for (i64 i = 0; i < n; ++i) cin >> a[i];
    i64 x = *max_element(a.begin(), a.end());
    while (m--) {
        char c; cin >> c;
        i64 l, r; cin >> l >> r;
        if (l <= x and x <= r) {
            x += 1 - 2 * (c == '-');
        }
        cout << x << ' ';
    }
    cout << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    i64 T; cin >> T;
    while(T--) solve();
    return 0;
}
