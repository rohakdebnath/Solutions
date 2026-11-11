#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    i64 n, k; cin >> n >> k;
    vector<i64> a (n); for (i64 i = 0; i < n; ++i) cin >> a[i], a[i]--;

    vector<vector<i64>> dp (62, vector<i64> (n));
    for (i64 i = 0; i < n; ++i) {
        dp[0][i] = a[i];
    }
    for (i64 i = 1; i < 62; ++i) {
        for (i64 j = 0; j < n; ++j) {
            dp[i][j] = dp[i - 1][dp[i - 1][j]];
        }
    }
    int j = 0;
    for (i64 i = 0; i < 62; ++i) {
        if (((1LL << i) & k) == 0) continue;
        j = dp[i][j];
    }
    cout << j << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}

