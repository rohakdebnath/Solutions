#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> dp (m); //dp[i][j] = using the first i elements how many subsequences can add to give j mod m, using space optimisation.
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        auto ndp = dp;
        for (int j = 0; j < m; ++j) {
            ndp[(j + a[i] % m) % m] += dp[j];
        }
        dp = ndp;
    }
    cout << dp[0] - 1 << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
