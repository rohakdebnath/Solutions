#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<vector<int>>> adj (2, vector<vector<int>> (n));
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        --a, --b;
        adj[0][a].push_back(b);
        adj[0][b].push_back(a);
    }
    for (int i = 0; i < n; ++i) {
        set<int> a;
        for (int j = 0; j < n; ++j) if (j != i) a.insert(j);
        for (int j: adj[0][i]) {
            a.erase(j);
        }
        for (int v: a) {
            adj[1][v].push_back(i);
            adj[1][i].push_back(v);
        }
    }
    vector<vector<int>> c (2, vector<int> (n, -1));
    auto dfs = [&] (auto&& self, int v, int col, int i) -> void{
        c[i][v] = col;
        for (int u: adj[i][v]) {
            if (c[i][u] == -1) {
                self(self, u, col, i);
            }
        }
    };

    for (int j = 0; j < 2; ++j) {
        for (int i = 0, col = 0; i < n; ++i) {
            if (c[j][i] == -1) {
                dfs(dfs, i, col, j);
                ++col;
            }
        }
    }
    if ((c[0][0] != c[0][n - 1]) or (c[1][0] != c[1][n - 1]) or (c[0][0] == -1) or (c[1][0] == -1)) {
        cout << "-1\n";
        return;
    }
    vector<vector<int>> d (2, vector<int> (n, -1));
    auto bfs = [&] (int ini, int i) {
        queue<int> q;
        q.push(ini);
        d[i][ini] = 0;
        while (!q.empty()) {
            int top = q.front();
            q.pop();
            for (int u: adj[i][top]) {
                if (d[i][u] == -1) {
                    d[i][u] = d[i][top] + 1;
                    q.push(u);
                }
            }
        }
    };
    for (int i = 0; i < 2; ++i) {
        bfs(0, i);
    } 
    cout << max(d[0][n - 1], d[1][n - 1]) << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
