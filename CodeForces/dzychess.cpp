#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<char>> g(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> g[i][j];
        }
    }
    auto dfs = [&] (auto&& self, int r, int c, int x) -> void {
        x ? g[r][c] = 'W' : g[r][c] = 'B';
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, -1, 0, 1};
        for (int i = 0; i < 4; ++i) {
            int nr = r + dx[i], nc = c + dy[i];
            if (nr >= 0 and nr < n and nc >= 0 and nc < m and g[nr][nc] == '.') self(self, nr, nc, !x);
        }
    };
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (g[i][j] == '.') dfs(dfs, i, j, 0);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << g[i][j];
        }
        cout << '\n';
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
