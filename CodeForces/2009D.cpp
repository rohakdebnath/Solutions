#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<vector<int>> c (2, vector<int> (n + 1));
    for (int i = 0; i < n; ++i) {
        int x, y; cin >> x >> y;
        ++c[y][x];
    }
    int ans = 0;
    for (int i = 1; i < n; ++i) {
        ans += min({c[0][i], c[1][i - 1], c[1][i + 1]}) + min({c[1][i], c[0][i - 1], c[0][i + 1]});
    }
    for (int i = 0; i <= n; ++i) {
        ans += min(c[0][i], c[1][i]) * (n - c[0][i] - c[1][i]);
    }
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
