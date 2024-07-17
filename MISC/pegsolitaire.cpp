#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int inf = 1e9;
void solve() {
    vector<vector<char>> g (5, vector<char> (9));
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 9; ++j) {
            char c; cin >> c;
            g[i][j] = c;
        }
    }
    auto cnt = [&] (decltype(g) y) -> int {
        int c = 0;
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 9; ++j) {
                c += y[i][j] == 'o';
            }
        }
        return c;
    };
    int minpeg = 8, minpegminmove = inf;
    map<decltype(g), int> m; //minimum moves to build the current config
    m[g] = 0;
    while (m.size()) {
        decltype(m) h;
        for (auto [t, v]: m) {
            for (int i = 0; i < 5; ++i) {
                for (int j = 0; j < 9; ++j) {
                    if (t[i][j] != 'o') continue;
                    if (i > 1 and t[i - 1][j] == 'o' and t[i - 2][j] == '.') {
                        auto x = t;
                        x[i - 2][j] = 'o', x[i][j] = '.', x[i - 1][j] = '.';
                        if (!h[x]) h[x] = v + 1;
                        else h[x] = min(h[x], v + 1);
                    } 
                    if (i < 3 and t[i + 1][j] == 'o' and t[i + 2][j] == '.') {
                        auto x = t;
                        x[i + 2][j] = 'o', x[i][j] = '.', x[i + 1][j] = '.';
                        if (!h[x]) h[x] = v + 1;
                        else h[x] = min(h[x], v + 1);
                    }
                    if (j > 1 and t[i][j - 1] == 'o' and t[i][j - 2] == '.') {
                        auto x = t;
                        x[i][j - 2] = 'o', x[i][j] = '.', x[i][j - 1] = '.';
                        if (!h[x]) h[x] = v + 1;
                        else h[x] = min(h[x], v + 1);
                    } 
                    if (j < 7 and t[i][j + 1] == 'o' and t[i][j + 2] == '.') {
                        auto x = t;
                        x[i][j + 2] = 'o', x[i][j] = '.', x[i][j + 1] = '.';
                        if (!h[x]) h[x] = v + 1;
                        else h[x] = min(h[x], v + 1);
                    } 
                }
            }
        }
        for (auto [u, v]: m) {
            int d = cnt(u);
            if (((d == minpeg) and (v < minpegminmove)) or (d < minpeg)) {
                minpeg = d;
                minpegminmove = v;
            }
        }
        m = h;
    }
    cout << minpeg << ' ' << minpegminmove << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
