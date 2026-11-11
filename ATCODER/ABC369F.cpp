#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int h, w, n; cin >> h >> w >> n;
    vector<vector<int>> g (h, vector<int> (w));
    for (int i = 0; i < n; ++i) {
        int r, c; cin >> r >> c; --r, --c;
        g[r][c] = 1;
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
