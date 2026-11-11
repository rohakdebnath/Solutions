#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int h, w; cin >> h >> w;
    vector<vector<int>> g (h, vector<int> (w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> g[i][j];
        }
    }
    int i = 0, j = 0;
    vector<array<int, 4>> ans;
    while (i < h and j < w) {
        // if (g[i][j] % 2 == 0) continue;
        if (i % 2 == 0) {
            while (j < w - 1) {
                ++j;
                if (g[i][j - 1] % 2) {
                    ans.push_back({i + 1, j, i + 1, j + 1});
                    ++g[i][j];
                }
            }
            if (i < h - 1) {
                if (g[i][j] % 2) {
                    ans.push_back({i + 1, j + 1, i + 2, j + 1});
                    ++g[i + 1][j];
                }
            }
            ++i;
        } else {
            while (j > 0) {
                --j;
                if (g[i][j + 1] % 2) {
                    ans.push_back({i + 1, j + 2, i + 1, j + 1});
                    ++g[i][j];
                }
            }
            if (i < h - 1) {
                if (g[i][j] % 2) {
                    ans.push_back({i + 1, j + 1, i + 2, j + 1});
                    ++g[i + 1][j];
                }
            }
            ++i;
        }
    }
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i][0] << ' ' << ans[i][1] << ' ' << ans[i][2] << ' ' << ans[i][3] << '\n'; 
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
