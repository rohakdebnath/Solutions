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
    vector<double> d (n), p (n); //d[i] = distance of i from root, p[i] = probablity of reaching node i
    p[0] = 1;
    double ans = 0; // ans = sigma(length of root * prob of reaching root)
    auto dfs = [&] (auto&& self, int v, int a) -> void{
        int s = adj[v].size() - (v != 0);
        bool leaf = true;

        for (int u: adj[v]) {
            if (u == a) continue;
            leaf = false;
            p[u] = p[v] * 1 / s;
            d[u] = 1 + d[v];
            self(self, u, v);
        }
        if (leaf) {
            ans += d[v] * p[v];
        }
    };
    dfs(dfs, 0, -1);
    cout << fixed << setprecision(8) << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
