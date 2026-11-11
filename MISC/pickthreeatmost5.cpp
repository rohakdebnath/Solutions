#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int inf = 1e9;
void solve() {
    int n; cin >> n;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> p (n + 1); partial_sum(a.begin(), a.end(), p.begin() + 1);
    vector<vector<int>> dp (n + 1, vector<int> (5 + 1, -inf)); //dp[i][j] = max sum if the jth segment ends at i
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = 0;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= 5; ++j) {
            dp[i + 1][j] = max(dp[i][j], dp[i + 1][j - 1]);
            if (i - 2 >= 0) dp[i + 1][j] = max(dp[i - 2][j - 1] + p[i + 1] - p[i - 2], dp[i + 1][j]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= 5; ++i) {
        ans = max(ans, dp[n][i]);
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
