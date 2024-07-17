#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> g (n, vector<int> (m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> g[i][j];
        }
    }

    auto dis = [&] (int x, int y) -> int {
        if (x < 0 or x >= n or y < 0 or y >= m) return 0;
        return g[x][y];
    };
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int t = 0;
            for (int k = 0; k < 4; ++k) {
                t = max(t, dis(i + dx[k], j + dy[k]));
            }
            if (t < g[i][j]) g[i][j] = t;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << g[i][j] << " \n"[j == m - 1];
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
