#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int inf = 1e9;
void solve(int l) {
    int n; cin >> n;
    vector<int> a (n + 2); for (int i = 0; i < n; ++i) cin >> a[i + 1];
    a[n + 1] = l;
    //dp[l][r] = min price to cut from l to r, dp[i][i + 1] = 0 frall i as the base case
    vector<vector<int>> dp (n + 2, vector<int> (n + 2, inf));
    for (int i = 0; i + 1 < n + 2; ++i) {
        dp[i][i + 1] = 0;
    }
    for (int d = 2; d < n + 2; ++d) {
        for (int i = 0; i + d < n + 2; ++i) {
            for (int k = i + 1; k < i + d; ++k) {
                dp[i][i + d] = min(dp[i][i + d], dp[i][k] + dp[k][i + d] + a[i + d] - a[i]);
            }
        }
    }
    cout << "The minimum cutting is " << dp[0][n + 1] << ".\n";
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    for (int T; cin >> T and T;) solve(T);
    return 0;
}
