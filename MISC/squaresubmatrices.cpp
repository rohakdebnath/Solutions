#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> dp (n + 1, vector<int> (m + 1)), g (n + 1, vector<int> (m + 1));
    //dp[i][j] = number of square submatrices in the submatrix 0, 0 to i, j
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> g[i + 1][j + 1];
            g[i + 1][j + 1] += g[i][j + 1] + g[i + 1][j] - g[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
            for (int l = 1; l <= min(i, j); ++l) {
                dp[i][j] += (g[i][j] - g[i][j - l] - g[i - l][j] + g[i - l][j - l] == l * l);
            }
        }
    }
    cout << dp[n][m] << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
