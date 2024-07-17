#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<vector<int>> a (n, vector<int> (m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    i64 s = 0;
    vector<vector<i64>> p (n + 1, vector<i64> (m + 1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c; cin >> c;
            p[i + 1][j + 1] = (c == '1' ? 1 : -1);
            s += p[i + 1][j + 1] * a[i][j];
            p[i + 1][j + 1] += p[i + 1][j] + p[i][j + 1] - p[i][j];
        }
    }
    int g = 0;
    for (int i = k; i <= n; ++i) {
        for (int j = k; j <= m; ++j) {
            i64 t = p[i][j] - p[i - k][j] - p[i][j - k] + p[i - k][j - k];
            g = gcd(g, t);
        }
    }
    if (s == 0 or (g and (s % g == 0))) cout << "YES\n";
    else cout << "NO\n";
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
