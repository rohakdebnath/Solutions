#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    i64 n, a, b; cin >> n >> a >> b;
    i64 g = gcd(a, b);
    vector<i64> c (n); for (i64 i = 0; i < n; ++i) cin >> c[i];
    if (n == 1) {
        cout << 0 << '\n';
        return;
    }
    sort(c.begin(), c.end());
    for (i64 i = n - 1; i >= 0; --i) {
        c[i] = (c[i] - c[0]) % g;
    }
    sort(c.begin(), c.end());
    i64 minrange = c[n - 1] - c[0];
    for (int i = n - 1; i >= 1; --i) {
        minrange = min(minrange, c[i - 1] - c[i] + g);
    }
    cout << minrange << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    i64 T; cin >> T;
    while(T--) solve();
    return 0;
}
