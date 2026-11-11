#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    i64 n, m; cin >> n >> m;
    vector<vector<pair<i64, i64>>> adj (n);
    for (i64 i = 0; i < m; ++i) {
        i64 a, b, w; cin >> a >> b >> w;
        --a, --b;
        adj[a].push_back({b, w});
        adj[b].push_back({a, -w});
    }
    vector<i64> vis (n);
    vector<i64> a (n);
    auto dfs = [&] (auto&& self, i64 v) -> void{
        if (vis[v]) return;
        vis[v] = 1;
        for (auto [u, w]: adj[v]) {
            a[u] = a[v] + w;
            self(self, u);
        }
    };
    for (i64 i = 0; i < n; ++i) {
        if (!vis[i]) dfs(dfs, i);
    }

    for (i64 i = 0; i < n; ++i) {
        cout << a[i] << " \n"[i == n - 1];
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
