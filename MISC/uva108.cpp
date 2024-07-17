#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<vector<int>> g (n + 1, vector<int> (n + 1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> g[i + 1][j + 1];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            g[i][j] += g[i - 1][j];
        }
    }
    int m = 0;
    auto e = [&] (int i, int j, int k) {
        return g[j][k] - g[i - 1][k];
    };
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            vector<int> dp (n + 1);
            for (int k = 1; k <= n; ++k) {
                dp[k] = max(dp[k - 1], 0) + e(i, j, k);
                m = max(m, dp[k]);
            }
        }
    }
    cout << m << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
