#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int inf = 1e9;
void solve() {
    int h, w; cin >> h >> w;
    vector<vector<int>> g (h, vector<int> (w, inf));
    queue<array<int, 2>> q;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            char c; cin >> c;
            if (c == '#') g[i][j] = 0;
            if (g[i][j] == 0) {
                q.push({i, j});
            }
        }
    }
    int m = 0;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, -1, 0, 1};
        for (int i = 0; i < 4; ++i) {
            int nx = dx[i] + x, ny = dy[i] + y;
            if (nx < h and nx >= 0 and ny < w and ny >= 0 and g[nx][ny] == inf) {
                g[nx][ny] = 1 + g[x][y];
                q.push({nx, ny});
                m = max(m, g[nx][ny]);
            }
        }
    }
    cout << m << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
