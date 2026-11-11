#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<vector<array<int, 2>>> adj (n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v, w; cin >> u >> v >> w;
        --u, --v;
        w %= 2;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<int> ans (n);
    auto dfs = [&] (auto&& self, int v, int p, int c) -> void{
        ans[v] = c;
        for (auto a: adj[v]) {
            if (a[0] != p) {
                self(self, a[0], v, c ^ a[1]);
            }
        }
    };
    dfs(dfs, 0, -1, 0);

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << '\n';
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
