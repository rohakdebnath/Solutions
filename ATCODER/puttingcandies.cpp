#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    i64 n, k; cin >> n >> k;
    vector<i64> a (n); for (i64 i = 0; i < n; ++i) cin >> a[i];

    vector<vector<i64>> dp (41, vector<i64> (n)); //dp[i][j] = if we start adding from jth index, then the total number of candies after (1 << i) moves
    dp[0] = std::move(a);
    for (i64 i = 1; i < 41; ++i) {
        for (i64 j = 0; j < n; ++j) {
            dp[i][j] = dp[i - 1][j] + dp[i - 1][(j + dp[i - 1][j]) % n];
        }
    }
    i64 ans = 0;
    for (i64 i = 0; i < 41; ++i) {
        if (((1LL << i) & k) == 0) continue;
        ans += dp[i][ans % n];
    }
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
