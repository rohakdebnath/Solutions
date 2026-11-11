#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int inf = 1e9;
void solve() {
    int n; cin >> n;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    //dp[i][j] = min number of brush strokes required to paint subarray i..j
    vector<vector<int>> dp (n, vector<int> (n, inf));
    for (int i = n - 1; i >= 0; --i) {
        dp[i][i] = 1; 
        for (int j = i + 1; j < n; ++j) {
            if (a[i] == a[j]) dp[i][j] = dp[i][j - 1];
            else {
                for (int k = i; k < j; ++k) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
                }
            }
        }
    }
    cout << dp[0][n - 1] << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
