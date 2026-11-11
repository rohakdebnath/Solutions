#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    i64 n; cin >> n;
    vector<i64> a (n); for (i64 i = 0; i < n; ++i) cin >> a[i];
    vector<i64> f (n, -2); // f[i] = earliest index j < i such that the sum of all elements from j to i equals 0, -1 if not found
    map<i64, i64> m;
    i64 s = 0;
    m[s] = -1;
    for (i64 i = 0; i < n; ++i) {
        s += a[i];
        if (m.find(s) != m.end()) {
            f[i] = m[s];
        }
        m[s] = i;
    }
    vector<i64> dp (n + 1); //dp[i] = max number of beautiful segments till ith index
    for (i64 i = 0; i < n; ++i) {
        dp[i + 1] = dp[i];
        if (f[i] != -2) {
            dp[i + 1] = max(dp[i + 1], (f[i] > -1 ? dp[f[i] + 1] : 0) + 1);
        }
    }
    cout << dp[n] << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    i64 T; cin >> T;
    while(T--) solve();
    return 0;
}
