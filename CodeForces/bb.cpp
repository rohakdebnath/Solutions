#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int inf = 1e9;
void solve() {
    int n; cin >> n;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];

    auto work = [&] (int x) {
        vector dp (n + 1, vector<int> (2, inf)); // dp[i][j] = minimum damage you get after ith element, either beating or getting beat at the ith segment. 0: ignore, 1: beat
        if (x) reverse(a.begin(), a.end());
        dp[0][0] = 0; 
        for (int i = 0; i < n; ++i) {
            dp[i + 1][0] = min(dp[i][1], dp[i][0]) + a[i];
            dp[i + 1][1] = (i - 2 >= 0 ? min(dp[i - 2][1], dp[i - 2][0]) : inf);
        }
        return max(dp[n][0], dp[n][1]);
    };
    int m = inf;
    for (int i = 0; i < 2; ++i) {
        m = min(m, work(i));
    }
    cout << m << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
