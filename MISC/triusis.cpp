#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int inf = 1e9;
void solve() {
    int n, m; cin >> n >> m;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> f;
    for (int i = 0; i < n; ++i) {
        if (m * (i + 1) >= a[i]) {
            f.push_back(m * (i + 1) - a[i]);
        }
    }
    int s = f.size();
    vector<i64> dp(s + 1, inf); 
    dp[0] = -inf;

    for (int i = 0; i < s; ++i) {
        i64 l = upper_bound(dp.begin(), dp.end(), f[i]) - dp.begin();
        dp[l] = f[i];
    }
    i64 ans = 0;
    for (int i = 0; i <= s; ++i) {
        if (dp[i] < inf) ans = i;
    }
    cout << n - ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; t = 1;
    while (t--) solve();
    return 0;
}
