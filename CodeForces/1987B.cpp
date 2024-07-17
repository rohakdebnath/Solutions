#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    int p = 0, l = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        int d = a[i] - l;
        l = max(l, a[i]);
        if (d >= 0) continue;
        d = -d;
        if (d > p) {
            d -= p;
            ans += 2 * d + p;
            p += d;
        } else {
            ans += d;
        }
    }
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
