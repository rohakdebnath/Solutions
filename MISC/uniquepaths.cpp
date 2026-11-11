//IMPORTANT: follwoing solution only find unique paths involving root node so essentially it is a WRONG solution for the given problem
//given a directed graph print if it has only a unique path between any two nodes, or not 
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj (n);
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
    }

    vector<int> path (n), vis (n);
    auto dfs = [&] (auto&& self, int v) -> bool { //dfs(r) returns true if the dfs subtree of v contains a unique path
        path[v] = 1;
        vis[v] = 1;

        for (int u: adj[v]) {
            if (vis[u] and !path[u]) return true;
            else if (!vis[u] and self(self, u)) return true;
        }

        path[v] = 0;
        return false;
    };

    cout << dfs(dfs, 0) << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
