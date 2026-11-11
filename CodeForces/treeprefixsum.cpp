//given a tree prefix sum from root zero. each node should contain the sum of the node value of it's parent.

#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];

    vector<vector<int>> adj (n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    auto dfs = [&] (auto&& self, int v, int p) ->void {
        for (int u: adj[v]) {
            if (u != p) {
                a[u] += a[v];
                self(self, u, v);
            }
        }
    };
    dfs(dfs, 0, -1);
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " \n"[i == n - 1];
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}

