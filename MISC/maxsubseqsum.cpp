#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    vector<i64> dp (n + 1); //dp[i] = max sum till i 
    for (int i = 0; i < n; ++i) {
        dp[i + 1] = max<i64>(dp[i], dp[i] + a[i]); //either include a[i] or dont
    }
    cout << dp[n] << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
