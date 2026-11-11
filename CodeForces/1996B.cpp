#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, k; cin >> n >> k;
    vector<vector<int>> g (n, vector<int> (n));
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        for (int j = 0; j < n; ++j) {
            g[i][j] = s[j] - '0';
        }
    }
    vector<int> s;
    for (int i = 0; i < n; i += k) {
        for (int j = 0; j < n; j += k) {
            s.push_back(g[i][j]);
        }
    }

    for (int i = 0; i < n / k; ++i) {
        for (int j = 0; j < n / k; ++j) {
            cout << s[i * (n / k) + j];
        }
        cout << '\n';
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
