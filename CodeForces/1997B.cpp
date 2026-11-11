#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<vector<int>> g (2, vector<int> (n));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> g[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < 2; ++i) {
        for (int j = 1; j < n - 1; ++j) {
            ans += (g[i][j] == '.' and g[!i][j - 1] == 'x' and g[!i][j + 1] == 'x' and g[i][j - 1] == '.' and g[i][j + 1] == '.');
        }
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
