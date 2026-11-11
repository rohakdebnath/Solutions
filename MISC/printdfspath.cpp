//given a tree our task is to print all the paths starting from vertex 0 and ending at all the leafs, (0 is never the root)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<vector<int>> adj (n);
    for (int i = 0; i < n - 1; ++i) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> vis (n);
    auto dfs = [&] (auto&& self, int v, vector<int>& path) ->void{
        vis[v] = 1;
        path.push_back(v);
        bool leaf = true;
        for (int u: adj[v]) {
            if (!vis[u]) {
                leaf = false;
                self(self, u, path);
            }
        }
        if (leaf) {
            for (int i = 0; i < path.size(); ++i) {
                cout << path[i] << " \n"[i == path.size() - 1];
            }
        }
        path.pop_back();
    };
    vector<int> path;
    dfs(dfs, 0, path);
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
