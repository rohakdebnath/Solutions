#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const i64 inf = 1e12;
void solve() {
    i64 n, c; cin >> n >> c;
    vector<i64> a (n); for (i64 i = 0; i < n; ++i) cin >> a[i];
    vector<vector<i64>> adj (n);
    for (i64 i = 0; i < n - 1; ++i) {
        i64 a, b; cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<vector<i64>> dp (2, vector<i64> (n, -inf)); //dp[i][j] = maximum coins from the subtree of j by keeping j safe or unsafe

    auto dfs = [&] (auto&& self, i64 v, i64 p) -> void {
        dp[0][v] = a[v];
        dp[1][v] = 0;
        for (i64 u: adj[v]) {
            if (u == p) continue;
            self(self, u, v);
            dp[0][v] += max(dp[0][u] - 2 * c, dp[1][u]);
            dp[1][v] += max(dp[0][u], dp[1][u]);
        }
    };
    dfs(dfs, 0, -1);

    cout << max(dp[0][0], dp[1][0]) << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    i64 T; cin >> T;
    while(T--) solve();
    return 0;
}
