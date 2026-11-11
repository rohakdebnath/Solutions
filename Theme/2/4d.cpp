#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {  
    int n, m; cin >> n >> m;
    vector g (1 << 8, vector<int> (1 << 8));

    for (int i = 0; i < (1 << 8); i += 2) {
        for (int j = 0; j < (1 << 8); j += 2) {
            int x = i / 2 * (1 << 8) + j / 2;
            g[i][j] = 4 * x;
            g[i][j + 1] = 4 * x + 1;
            g[i + 1][j] = 4 * x + 2;
            g[i + 1][j + 1] = 4 * x + 3;
        }
    }
    cout << n * m << '\n';
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << g[i][j] << " \n"[j == m - 1];
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
