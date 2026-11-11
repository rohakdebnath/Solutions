#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, k; cin >> n >> k;
    vector<vector<int>> adj (n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int s = -1;
    vector<int> stein (n);
    for (int i = 0; i < k; ++i) {
        int x; cin >> x;
        if (i == 0) s = x - 1;
        stein[x - 1] = 1;
    }
    auto dfs = [&] (auto&&self, int v, int p) -> void{
        for (int u: adj[v]) {
            if (u != p) {
                self(self, u, v);
                stein[v] |= stein[u];
            }
        }
    };
    dfs(dfs, s, -1);
    cout << accumulate(stein.begin(), stein.end(), 0) << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
