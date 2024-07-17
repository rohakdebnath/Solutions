#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    vector<vector<int>> dp (n + 1, vector<int> (n + 1)); //dp[i][j] = number of ways to remove substring i..j

    for (int i = n - 1; i >= 0; --i) {
        for (int j = i; j < n; ++j) {
            dp[i][j] = 1 + dp[i + 1][j];
            if (i + 1 < n and a[i] == a[i + 1]) dp[i][j] = 1 + dp[i + 2][j];
            for (int k = i + 2; k <= j; ++k) {
                if (a[i] == a[k]) {
                    dp[i][j] = min(dp[i][j], dp[i + 1][k - 1] + dp[k + 1][j]);
                }
            }
        }
    }
    cout << dp[0][n - 1] << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
