//16
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    vector<vector<int>> dp (k + 1, vector<int> (2001));
    auto dfs = [&] (auto&& self, int k, int v) {
        if (dp[k][v]) return;
        dp[k][v] = 1;
        if (k == 0) return;
        for (int i = 0; i < n; ++i) {
            self(self, k - 1, v ^ a[i]);
        }
    };
    dfs(dfs, k, 0);
    cout << accumulate(dp[0].begin(), dp[0].end(), 0) << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}

