#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int inf = 1e9;
void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> g (n + 1, vector<int> (m + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> g[i][j];
        }
    }
    vector<vector<vector<int>>> dp (4, vector<vector<int>> (n + 2, vector<int> (m + 2, -inf)));
    //dp[d][i][j] = max pts by reaching i, j from corner d (0, 1, 2, 3 -> tl, tr, br, bl)
    dp[0][1][1] = g[1][1];
    dp[1][1][m] = g[1][m];
    dp[2][n][m] = g[n][m];
    dp[3][n][1] = g[n][1];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if(!(i == 1 and j == 1))
                dp[0][i][j] = max(dp[0][i - 1][j], dp[0][i][j - 1]) + g[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = m; j >= 1; --j) {
            if(!(i == 1 and j == m))
                dp[1][i][j] = max(dp[1][i - 1][j], dp[1][i][j + 1]) + g[i][j];
        }
    }
    for (int i = n; i >= 1; --i) {
        for (int j = m; j >= 1; --j) {
            if(!(i == n and j == m))
                dp[2][i][j] = max(dp[2][i + 1][j], dp[2][i][j + 1]) + g[i][j];
        }
    }
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= m; ++j) {
            if(!(i == n and j == 1))
                dp[3][i][j] = max(dp[3][i + 1][j], dp[3][i][j - 1]) + g[i][j];
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int x = dp[0][i][j - 1] + dp[2][i][j + 1] + dp[1][i - 1][j] + dp[3][i + 1][j];
            int y = dp[0][i - 1][j] + dp[2][i + 1][j] + dp[1][i][j + 1] + dp[3][i][j - 1];
            ans = max({ans, x, y});
        }
    }
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
