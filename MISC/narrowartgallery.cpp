#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int inf = 1e9;
void solve() {
    int n, k; cin >> n >> k;
    //dp[i][j][k] = min sum of excluded rooms till the ith row when j rooms are removed and the room removed is k (0: none removed, 1: left removed, 2: right removed), we can build a push from these
    vector<vector<vector<int>>> dp (n + 1, vector<vector<int>> (n + 1, vector<int> (3, inf)));
    dp[0][0][0] = 0;
    vector<int> a (n), b (n); 
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int p = 0; p < 3; ++p) {
                if (p == 0) {
                    dp[i + 1][j][0] = min(dp[i + 1][j][0], dp[i][j][p]);
                    dp[i + 1][j + 1][1] = min(dp[i + 1][j + 1][1], dp[i][j][p] + a[i]);
                    dp[i + 1][j + 1][2] = min(dp[i + 1][j + 1][2], dp[i][j][p] + b[i]);
                } else if (p == 1) {
                    dp[i + 1][j][0] = min(dp[i + 1][j][0], dp[i][j][p]);
                    dp[i + 1][j + 1][1] = min(dp[i + 1][j + 1][1], dp[i][j][p] + a[i]);
                } else {
                    dp[i + 1][j][0] = min(dp[i + 1][j][0], dp[i][j][p]);
                    dp[i + 1][j + 1][2] = min(dp[i + 1][j + 1][2], dp[i][j][p] + b[i]);
                }
            }
        }
    }
    int l = inf;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < 3; ++j) {
            l = min(l, dp[i][k][j]);
        }
    }
    cout << accumulate(a.begin(), a.end(), 0) + accumulate(b.begin(), b.end(), 0) - l << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; T = 1;
    while(T--) solve();
    return 0;
}
