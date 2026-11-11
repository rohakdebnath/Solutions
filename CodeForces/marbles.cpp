#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    vector<vector<int>> g (101, vector<int> (101));
    for (int i = 0; i <= 100; ++i) {
        g[0][i] = g[i][0] = g[i][i] = 1 << 8;
    }
    g[0][0] = 0;
    for (int i = 1; i <= 100; ++i) {
        for (int j = 1; j <= 100; ++j) {
            if (i == j) continue;
            vector<int> s (257);
            for (int u = 1; u <= 100; ++u) {
                if (i - u >= 0) s[g[i - u][j]] = 1;
                if (j - u >= 0) s[g[i][j - u]] = 1;
                if (i - u >= 0 and j - u >= 0) s[g[i - u][j - u]] = 1;
            }
            int mex = 0;
            while (s[mex]) ++mex;
            g[i][j] = mex;
        }
    }
    int xsum = 0;
    int n; cin >> n;
    while (n--) {
        int a, b; cin >> a >> b;
        xsum ^= g[a][b];
    }
    cout << (xsum > 0 ? "Y\n": "N\n");
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
