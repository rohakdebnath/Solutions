#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const i64 inf = 2e15;
void solve() {
    i64 n; cin >> n;
    vector<i64> a (n); for (i64 i = 0; i < n; ++i) cin >> a[i];
    vector<vector<i64>> dp (n + 1, vector<i64> (2, -inf)); //dp[i][j] = maximum points you can get from the first i elements when the monsters you already killed % 2 == j
    //we can either kill the ith monster or let it go
    dp[0][0] = 0;
    for (i64 i = 0; i < n; ++i) {
        dp[i + 1][0] = max(dp[i + 1][0], dp[i][0]);
        dp[i + 1][1] = max(dp[i + 1][1], dp[i][0] + a[i]);
        dp[i + 1][1] = max(dp[i + 1][1], dp[i][1]);
        dp[i + 1][0] = max(dp[i + 1][0], dp[i][1] + 2 * a[i]);
    }
    cout << *max_element(dp[n].begin(), dp[n].end()) << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
