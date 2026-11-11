#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int inf = 1e9;
void solve() {
    int n, x, y; cin >> n >> x >> y;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> b (n); for (int i = 0; i < n; ++i) cin >> b[i];

    vector<vector<int>> dp (n + 1, vector<int> (2, inf)); //dp[i][j] = min cost to reach jth pos
    dp[0][1] = dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        dp[i + 1][0] = min({dp[i + 1][0], dp[i][0] + a[i], dp[i][1] + a[i] + y});
        dp[i + 1][1] = min({dp[i + 1][1], dp[i][1] + b[i], dp[i][0] + b[i] + y});
    }
    cout << min(dp[n][0], dp[n][1]) << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
