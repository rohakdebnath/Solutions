#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<vector<int>> adj (n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> d (n); //depth of node i
    vector<int> m (n); //m[i] = max height of anyone in the subtree of i
    vector<int> f (n + 1); //f[h] = number of removals needed to keep height of h

    auto dfs = [&] (auto&& self, int v, int p) -> void{
        m[v] = d[v];
        for (int u: adj[v]) {
            if (u == p) continue;
            d[u] = d[v] + 1;
            self(self, u, v);
            m[v] = max(m[v], m[u]);
        }
        ++f[0];
        --f[d[v]];
        ++f[m[v] + 1];
    };
    dfs(dfs, 0, -1);
    partial_sum(f.begin(), f.end(), f.begin());
    cout << *min_element(f.begin(), f.end() - 1) << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
