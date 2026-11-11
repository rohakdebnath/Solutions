#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int inf = 1e9;
void solve() {
    int n, q; cin >> n >> q;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    //def: dp[i][j] = rangemin(i to i + (1 << j) - 1)
    //update: dp[i][j] = min(dp[i][j - 1], dp[i + 1 << (j - 1)][j - 1])
    vector<vector<int>> dp (n, vector<int> (log2(n) + 1, inf));
    for (int i = 0; i < n; ++i) {
        dp[i][0] = a[i];
    }
    for (int j = 1; j <= log2(n); ++j) {
        for (int i = 0; i + (1 << j) <= n; ++i) {
            dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
        }
    }
    while (q--) {
        int l, r; cin >> l >> r; --l, --r;
        int p = log2(r - l + 1);
        cout << min(dp[l][p], dp[r + 1 - (1 << p)][p]) << '\n';
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
