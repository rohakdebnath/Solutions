#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, x; cin >> n >> x;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> b (n); for (int i = 0; i < n; ++i) cin >> b[i];
    vector<int> dp (x + 1); //dp[i] = max pages you can buy with i money
    for (int i = 0; i < n; ++i) {
        for (int j = x; j > 0; --j) {
            if (j - a[i] >= 0) dp[j] = max(dp[j], dp[j - a[i]] + b[i]);
        }
    }
    cout << dp[x] << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; t = 1;
    while (t--) solve();
    return 0;
}
