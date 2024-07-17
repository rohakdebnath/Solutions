#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int inf = 1e9;
void solve() {
    int m, s; cin >> m >> s;
    vector<vector<i64>> dp (s + 1, vector<i64> (s + 1, inf)); // dp[i][j] = minimum coins needed to get i conv. and j IT pts
    dp[0][0] = 0;
    for (int i = 0; i < m; ++i) {
        int c, t; cin >> c >> t;
        for (int j = 0; j <= s - c; ++j) {
            for (int k = 0; k <= s - t; ++k) {
                dp[j + c][k + t] = min(dp[j + c][k + t], dp[j][k] + 1);
            }
        }
    }
    int ans = inf;
    for (int i = 0; i <= s; ++i) {
        int x = sqrt(s * s - i * i);
        if (x * x != s * s - i * i) continue;
        ans = min<i64>(ans, dp[i][x]);
    }
    if (ans == inf) cout << "not possible\n";
    else cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
