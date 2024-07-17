#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int inf = 1e9;
void solve() {
    int x, y; cin >> x >> y;
    vector<int> a, b;
    int l, m; cin >> l >> m;
    a.push_back(l); b.push_back(m);
    int q; cin >> q;
    a.resize(q + 1);
    b.resize(q + 1);
    for (int i = 0; i < q; ++i) {
        cin >> a[i + 1] >> b[i + 1];
    }
    vector<vector<int>> grid (q + 1, vector<int> (q + 1));
    for (int i = 0; i < q + 1; ++i) {
        for (int j = 0; j < q + 1; ++j) {
            grid[i][j] = abs(a[i] - a[j]) + abs(b[i] - b[j]);
        }
    }
    vector<vector<int>> dp (1 << (q + 1), vector<int> (q + 1, inf)); //dp[i][j] = min distance to travel a subset i ending at j
    dp[1][0] = 0;
    for (int i = 0; i < 1 << (q + 1); ++i) {
        for (int j = 0; j < q + 1; ++j) {
            for (int k = 0; k < q + 1; ++k) {
                if (dp[i][j] == inf or i & (1 << k)) continue;
                dp[i | 1 << k][k] = min(dp[i | 1 << k][k], dp[i][j] + grid[j][k] + ((i | (1 << k)) == ((1 << (q + 1)) - 1) ? grid[0][k] : 0));
            }
        }
    }
    cout << "The shortest path has length " << *min_element(dp[(1 << (q + 1)) - 1].begin(), dp[(1 << (q + 1)) - 1].end()) << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
