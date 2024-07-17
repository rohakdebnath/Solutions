#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> p (n);
    for (int i = n - 2; i >= 0; --i) {
        p[i] = p[i + 1] + (a[i] >= a[i + 1]);
    }
    int ans = p[0], s = 0;
    for (int i = 0; i < n; ++i) {
        s += (i > 0 ? a[i] >= a[i - 1] : 0);
        int t = 1 + s + (i < n - 1 ? p[i + 1] : 0);
        ans = min(ans, t);
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
