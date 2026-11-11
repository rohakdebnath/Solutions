#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<int> a (n + 1); for (int i = 1; i <= n; ++i) cin >> a[i];
    vector<bool> dp (n + 1); dp[0] = 1; //dp[i] = 1 if there exists an interpretation where the prefix i is valid
    //each element might be the cardinality of either front or back or none.
    for (int i = 1; i <= n; ++i) {
        if (i + a[i] <= n) dp[i + a[i]] = dp[i + a[i]] or dp[i - 1];
        if (i - a[i] - 1 >= 0) dp[i] = dp[i] or dp[i - a[i] - 1];
    }
    cout << (dp[n] ? "YES\n": "NO\n");
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
