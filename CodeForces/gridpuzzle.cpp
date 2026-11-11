#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int inf = 1e9;
void solve() {
    int n; cin >> n;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    vector<vector<int>> dp (n + 1, vector<int> (3, inf)); //dp[i][j = 0..2] = min operation till ith element and the operation used is of type j
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] > 4) {
            dp[i + 1][0] = min({dp[i + 1][0], dp[i][0] + (a[i] > 0), dp[i][1] + (a[i] > 0)});
        } else {
            dp[i + 1][0] = min({dp[i + 1][0], dp[i][0] + (a[i] > 0), dp[i][1] + (a[i] > 0)});
            if (i - 1 >= 0 and a[i - 1] <= 4) dp[i + 1][2] = min(dp[i + 1][2], dp[i - 1][2] + 2);
            if (i - 2 >= 0 and a[i - 1] <= 4 and a[i - 2] <= 2) dp[i + 1][2] = min(dp[i + 1][2], min(dp[i - 2][0], dp[i - 2][1]) + 2);
            if (a[i] <= 2) {
                dp[i + 1][1] = min(dp[i + 1][1], dp[i][2] + 1);
                if (i - 1 >= 0 and a[i - 1] <= 2) dp[i + 1][1] = min(dp[i + 1][1], min(dp[i - 1][1], dp[i - 1][0]) + 1);
            }
        }
    }

    cout << min(dp[n][0], dp[n][1]) << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}



// Notes:
// if a[i] > 4 always use a long. 
// we will never have to use two perfectly stacked squares. just use two rows
// we will only use three types of paints, one row operation, a block, or a block stacked on top of another block with exactly one row common
// a staggered stack must be followed by a another staggered block or a block, cant use a row after a staggered block, also staggered blocks take up two operations
// => use 2D dp
