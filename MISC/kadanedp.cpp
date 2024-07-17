#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    vector<i64> dp (n + 1); //max sum you can get from a segment ending at i
    for (int i = 0; i < n; ++i) {
        dp[i + 1] = max<i64>(a[i], dp[i] + a[i]); // either include a[i] in the previous one or start a new
    }
    cout << *max_element(dp.begin() + 1, dp.end()) << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; T = 1;
    while(T--) solve();
    return 0;
}
