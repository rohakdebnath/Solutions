#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int inf = 1e9;
void solve() {
    int n; cin >> n;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    vector<vector<int>> dp (n + 1, vector<int> (n + 1)); //dp[i][j] = min ops to remove i..j

    for (int i = n - 1; i >= 0; --i) {
        for (int j = i; j < n; ++j) {
            if (a[i] == a[j]) dp[i][j] = (j - 1 >= 0) * dp[i + 1][j - 1] + (j - i <= 1);
            else dp[i][j] = inf;
            for (int k = i; k < j; ++k) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
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
