#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    i64 n; cin >> n;
    vector<i64> a (n); for (i64 i = 0; i < n; ++i) cin >> a[i];
    vector<i64> dp (n); //dp[i] == longest AP ending at index i
    if (n == 1) {
        cout << "1\n";
        return;
    }
    dp[0] = 1, dp[1] = 2;
    for (i64 i = 2; i < n; ++i) {
        dp[i] = 2;
        if (a[i] - a[i - 1] == a[i - 1] - a[i - 2]) dp[i] = dp[i - 1] + 1;
    }
    cout << accumulate(dp.begin(), dp.end(), 0LL) << '\n'; 
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
