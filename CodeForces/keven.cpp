#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int k; cin >> k;
    string s; cin >> s;
    int n = s.size(); s += s;
    int m = 0;
    vector<vector<int>> dp (n);
    for (int d = 2; d < n; d += 2) {
        auto& p = dp[d];
        int x = 0;
        for (int i = 0; i < d/2; ++i) {
            x += s[i] != s[i + d/2];
        }
        if (x <= k and d >= m) {
            m = d;
            p.push_back(0);
        }
        for (int j = 1; j + d <= 2 * n; ++j) {
            x += s[j + d/2 - 1] != s[j + d - 1];
            x -= s[j - 1] != s[j + d/2 - 1];
            if (x <= k and d >= m) {
                m = d;
                p.push_back(j);
            }
        }
    }
    if (m == 0) {
        cout << '\n';
        return;
    }
    auto p = dp[m];
    vector<string> f;
    for (int i: p) {
        f.push_back(s.substr(i, m));
    }
    sort(f.begin(), f.end());
    cout << f[0] << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}


