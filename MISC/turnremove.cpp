#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    vector<vector<int>> dp (n , vector<int> (n)); //dp[i][j] is max value to reach subsegment a[i: j], dp[0: n - 1] = 0 obviously
    int m = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = n - 1; j >= i; --j) { //push influence of segment i..j to i + 1..j and i..j - 1 as long as they dont cross ofcourse
            if (i + 1 < n) dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + (n - j + i) * a[i]), m = max(m, dp[i + 1][j]);
            if (j - 1 >= 0) dp[i][j - 1] = max(dp[i][j - 1], dp[i][j] + (n - j + i) * a[j]), m = max(m, dp[i][j - 1]);
        }
    }
    cout << m << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; T = 1;
    while(T--) solve();
    return 0;
}
