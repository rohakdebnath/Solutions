#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<vector<int>> adj (n);
    vector<array<int, 2>> edge;
    int ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        edge.push_back({a, b});
    }

    queue<int> q; q.push(0);
    map<array<int, 2>, int> edgecol;
    vector<int> pecol (n, -1); //pecol[i] = color of edge betwen i and it's parent
    
    auto dfs = [&] (auto&& self, int v, int p) -> void {
        ans = max<int>(ans, adj[v].size());
        int c = 0;
        for (int u: adj[v]) {
            if (u != p) {
                if (c == pecol[v]) ++c;
                pecol[u] = edgecol[{u, v}] = edgecol[{v, u}] = c++;
                self(self, u, v);
            }
        }
    };
    dfs(dfs, 0, -1);
    cout << ans << '\n';
    for (int i = 0; i < n - 1; ++i) {
        cout << edgecol[edge[i]] + 1 << '\n';
    }
    
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
