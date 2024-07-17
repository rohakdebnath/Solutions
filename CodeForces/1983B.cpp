#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> g (n, vector<int> (m)), h (n, vector<int> (m));
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        for (int j = 0; j < m; ++j) {
            g[i][j] = s[j] - '0';
        }
    }
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        for (int j = 0; j < m; ++j) {
            h[i][j] = s[j] - '0';
        }
    }
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m - 1; ++j) {
            int x = (h[i][j] - g[i][j] + 3) % 3;
            int y = (3 - x) % 3;
            g[i][j] = (g[i][j] + x) % 3;
            g[i + 1][j + 1] = (g[i + 1][j + 1] + x) % 3;
            g[i + 1][j] =  (g[i + 1][j] + y) % 3;
            g[i][j + 1] = (g[i][j + 1] + y) % 3;
        }
    }
    cout << (h == g ? "YES\n": "NO\n");
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
