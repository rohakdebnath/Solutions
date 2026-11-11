#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    while (m--) {
        int a, b; cin >> a >> b;
        adj[b - 1].push_back(a - 1);
    }
    vector<int> vis(n), order;
    auto dfs = [&](int root, bool finish) {
        vector<int> st {root};
        while (!st.empty()) {
            int u = st.back(); st.pop_back();
            if (u < 0) {
                order.push_back(~u);
                continue;
            }
            if (vis[u]) continue;
            vis[u] = 1;
            if (finish) st.push_back(~u);
            for (int v: adj[u]) {
                if (!vis[v]) st.push_back(v);
            }
        }
    };
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) dfs(i, true);
    }
    reverse(order.begin(), order.end());
    fill(vis.begin(), vis.end(), 0);
    int ans = 0;
    for (int u: order) {
        if (!vis[u]) ++ans, dfs(u, false);
    }
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
