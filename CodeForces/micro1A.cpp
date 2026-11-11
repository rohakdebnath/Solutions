#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    array<array<char, 3>, 3> a;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> a[i][j];
        }
    }
    //ill brute force it

    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    array<array<bool, 3>, 3> vis;
    auto valid = [&] (int x, int y) {
        return x >= 0 and x < 3 and y >= 0 and y < 3 and !vis[x][y];
    };
    vector<string> res;
    auto dfs = [&] (auto&& self, int x, int y, string path) {
        if (path.size() == 3) {
            res.push_back(path);
            return;
        }
        for (int d = 0; d < 8; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (valid(nx, ny)) {
                vis[nx][ny] = true;
                self(self, nx, ny, path + a[nx][ny]);
                vis[nx][ny] = false;
            }
        }
    };

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            vis[i][j] = true;
            dfs(dfs, i, j, string(1, a[i][j]));
            vis[i][j] = false;
        }
    }
    sort(res.begin(), res.end());
    cout << res[0] << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
