#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    vector<vector<int>> dp (n + 2, vector<int> (n + 2)); //dp[i][j] = maximum pts i can get when in range i..j I am the one who moves
    for (int i = n - 1; i >= 0; --i) {
        for (int j = i; j < n; ++j) {
            dp[i + 1][j + 1] = max(-dp[i + 1][j] + a[j], -dp[i + 2][j + 1] + a[i]);
        }
    }
    cout << dp[1][n] << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
//1 2 10 4
