#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const i64 inf = 1e12;
void solve() {
    int n, m; cin >> n >> m;
    vector<array<int, 3>> edge (m);
    vector<vector<i64>> d (n, vector<i64> (n, inf));
    for (int i = 0; i < n; ++i) {
        d[i][i] = 0;
    }
    for (int i = 0; i < m; ++i) {
        int u, v, t; cin >> u >> v >> t;
        --u, --v;
        edge[i] = {u, v, t};
        d[u][v] = d[v][u] = min<i64>(d[v][u], t);
    }
    for (int k = 0; k < n; k++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    int q; cin >> q;
    while (q--) {
        int k; cin >> k;
        vector<int> a (k); for (int i = 0; i < k; ++i) cin >> a[i], --a[i];
        vector<int> nodes = {0, n - 1};
        for (int i = 0; i < k; ++i) {
            nodes.push_back(edge[a[i]][0]);
            nodes.push_back(edge[a[i]][1]);
        }
        sort(nodes.begin(), nodes.end());
        nodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());
        int s = nodes.size();
        vector<int> id (n);
        for (int i = 0; i < s; ++i) {
            id[nodes[i]] = i;
        }
        vector<vector<i64>> dp (1 << k, vector<i64> (s, inf)); //dp[i][j] = minimum cost to cover bitmask i bridges and you are currently at node j (j can be any node)
        //we will take each bitmask and then try to calculate the minimum cost by making our last node = either of the end of the current bridge then we need to calc all the other edges we can reach from our final position
        dp[0][0] = 0; //cost to cover no bridge and ur at node 0

        for (int i = 0; i < (1 << k); ++i) {
            for (int j = 0; j < k; ++j) {
                if (i >> j & 1) {
                    int l = edge[a[j]][0];
                    int r = edge[a[j]][1];
                    int w = edge[a[j]][2];
                    dp[i][id[l]] = min(dp[i][id[l]], dp[i ^ (1 << j)][id[r]] + w);
                    dp[i][id[r]] = min(dp[i][id[r]], dp[i ^ (1 << j)][id[l]] + w);
                }
            }
            for (int j = 0; j < s; ++j) {
                for (int k = 0; k < s; ++k) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + d[nodes[k]][nodes[j]]);
                }
            }
        }
        cout << dp[(1 << k) - 1][id[n - 1]] << '\n';
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
