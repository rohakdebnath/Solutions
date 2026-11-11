#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {  
    i64 n; cin >> n;
    vector<i64> a (n); for (i64 i = 0; i < n; ++i) cin >> a[i];
    vector<i64> dp (n); //dp[i] = max score when a jump ends at ith stone
    dp[0] = 0;
    for (i64 i = 1; i < n; ++i) {
        for (i64 j = 1; i - j >= 0; ++j) {
            dp[i] = max(dp[i], dp[i - j] + j * a[i]); // i think this can be improved using CHT but idont want to implement that right now
        }
    }
    cout << dp[n - 1] << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}

