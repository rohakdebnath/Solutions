#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int inf = 1000;
vector<vector<int>> g (inf + 1, vector<int> (inf + 1, -1));
void solve() {
    int n; cin >> n;
    int xsum = 0;
    for (int i = 0; i < n; ++i) {
        int r, c; cin >> r >> c;
        xsum ^= g[r - 1][c - 1];
    }
    cout << (xsum > 0 ? "First\n": "Second\n");
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    for (int i = 0; i <= 1; ++i) {
        g[0][i] = g[i][0] = 0;
    }
    auto dfs = [&] (auto&&self, int r, int c) -> int{
        if (g[r][c] != -1) return g[r][c];
        int dx[] = {1, -1, -2, -2};
        int dy[] = {-2, -2, 1, -1};
        map<int, bool> s;

        for (int i = 0; i < 4; ++i) {
            int nr = r + dx[i], nc = c + dy[i];
            if (nr < 15 and nr >= 0 and nc >= 0 and nc < 15)
            s[self(self, nr, nc)] = 1;
        }
        int mex = 0;
        while (s[mex]) ++mex;
        return g[r][c] = mex;
    };
    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j < 15; ++j) {
            if (g[i][j] == -1) dfs(dfs, i, j);
        }
    }
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
