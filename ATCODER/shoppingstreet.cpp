#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int inf = 1e9;
void solve() {
    int n; cin >> n;
    vector<vector<int>> f (n, vector<int> (10));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 10; ++j) {
            cin >> f[i][j];
        }
    }
    vector<vector<int>> p (n, vector<int> (11));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 11; ++j) {
            cin >> p[i][j];
        }
    }
    int ans = -inf;
    for (int b = 1; b < (1 << 10); ++b) {
        vector<int> c (n);
        for (int i = 0; i < 10; ++i) {
            int o = (b >> i) & 1;
            for (int j = 0; j < n; ++j) {
                if (f[j][i] and o) ++c[j];
            }
        }
        int t = 0;
        for (int i = 0; i < n; ++i) {
            t += p[i][c[i]];
        }
        ans = max(ans, t);
    }
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
