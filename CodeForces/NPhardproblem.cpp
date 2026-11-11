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
        adj[b].push_back(a);
    }

    vector<int> c (n, -1);
    bool bip = true;
    auto dfs = [&] (auto&& self, int v, int col) -> void{
        if (c[v] != -1) {
            if (c[v] != col) bip = false;
            return;
        }
        c[v] = col;
        for (int u: adj[v]) {
            self(self, u, !col);
        }
    };

    for (int i = 0; i < n; ++i) {
        if (c[i] == -1) {
            dfs(dfs, i, 0);
        }
    }
    vector<vector<int>> group (2);
    if (!bip) {
        cout << "-1\n";
    } else {
        for (int i = 0; i < n; ++i) {
            group[c[i]].push_back(i + 1);
        }
        for (int i = 0; i < 2; ++i) {
            cout << group[i].size() << '\n';
            for (int x: group[i]) {
                cout << x << ' ';
            }
            cout << '\n';
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
