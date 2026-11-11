#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<vector<int>>> adj (m, vector<vector<int>> (n)); //m adjacency lists

    for (int i = 0; i < m; ++i) {
        int a, b, c; cin >> a >> b >> c;
        --a, --b, --c;
        adj[c][a].push_back(b);
        adj[c][b].push_back(a);
    }
    vector<vector<int>> color (m, vector<int> (n));
    auto dfs = [&] (auto&& self, int c, int v, int col) -> void{
        color[c][v] = col;
        for (int u: adj[c][v]) {
            if (!color[c][u]) {
                self(self, c, u, col);
            }
        }
    };
    for (int i = 0; i < m; ++i) {
        int c = 1;
        for (int j = 0; j < n; ++j) {
            if (!color[i][j]) dfs(dfs, i, j, c++);
        }
    }
    int q; cin >> q;
    for (int i = 0; i < q; ++i) {
        int a, b; cin >> a >> b;
        --a, --b;
        int count = 0;
        for (int j = 0; j < m; ++j) {
            count += color[j][a] == color[j][b];
        }
        cout << count << '\n';
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
