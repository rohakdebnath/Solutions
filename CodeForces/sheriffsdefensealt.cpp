//Problem: given a tree and node values, you can pick a node but all it's neighbours upto a distance of 2 gets subtracted by c, find max nodes you can pick
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, c; cin >> n >> c;
    vector<vector<int>> adj (n);
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>> dp (1 << 2, vector<int> (n)); //dp[i][j] = maximum coins from the subtree of j when i type of influence is faced by the parent
    //0: influence of no nodes till now reach the parent
    //1: influence of the children only reaches the parent
    //2: influence of the current node only reach the parent (also means the current node is active)
    //3: influence of the current node and the children reach the parent (curr node active)
    auto dfs = [&] (auto&& self, i64 v, i64 p) -> void {
        dp[2][v] =  a[v];
        dp[3][v] = a[v];
        for (i64 u: adj[v]) {
            if (u == p) continue;
            self(self, u, v);
            dp[0][v] += max(dp[1][u], dp[0][u]);
            dp[1][v] += max(dp[2][u], dp[3][u]);
            dp[2][v] += max({dp[1][u] - 2 * c, dp[0][u]});
            dp[3][v] += max(dp[2][u] - 2 * c, dp[3][u] - 4 * c);
        }
    };
    dfs(dfs, 0, -1);
    cout << max({dp[0][0], dp[1][0], dp[2][0], dp[3][0]}) << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
