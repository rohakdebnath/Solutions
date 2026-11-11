#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    int sx = sqrt(n);
    string s; cin >> s;
    if (sx * sx != n) {
        cout << "No\n";
        return;
    }
    vector<vector<int>> g (sx, vector<int> (sx));
    for (int i = 0; i < sx; ++i) {
        for (int j = 0; j < sx; ++j) {
            g[i][j] = s[i * sx + j] == '1';
            if (i == 0 or i == sx - 1 or j == 0 or j == sx - 1) {
                if (g[i][j] == 0) {
                    cout << "No\n";
                    return;
                }
            } else {
                if (g[i][j]){
                    cout << "No\n";
                    return;
                }
            }
        }
    }
    cout << "Yes\n";
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
