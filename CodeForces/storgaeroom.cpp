#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<vector<int>> g (n, vector<int> (n));
    vector<int> a (n, (1 << 30) - 1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> g[i][j];
            if (i == j) g[i][j] = (1 << 30) - 1;
            a[i] &= g[i][j];
            a[j] &= g[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            if ((a[i] | a[j]) != g[i][j]) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " \n"[i == n - 1];
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}

