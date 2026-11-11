#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {  
    int n, m; cin >> n >> m;
    vector g (n, vector<int> (m));
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        for (int j = 0; j < m; ++j) {
            g[i][j] = s[j] - '0';
        }
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            int x = g[i][j] + g[i - 1][j] + g[i][j - 1] + g[i - 1][j - 1];
            if (x == 3) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
