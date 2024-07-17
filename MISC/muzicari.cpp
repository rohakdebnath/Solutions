#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int t, n; cin >> t >> n;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    vector<vector<int>> dp (t + 1, vector<int> (n + 1)); //dp[j][i] = 1 if sum j can be made using ith element in it, otherwise 0, dp[j][n] means j can be made using atleast one of the a_i's
    dp[0][n] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = t; j >= 0; --j) {
            if (j - a[i] >= 0) dp[j][i] = dp[j - a[i]][n] or dp[j][i];
            if (dp[j][i]) dp[j][n] = 1;
        }
    }
    i64 s = t;
    while (!dp[s][n]) --s;

    vector<int> mark (n);
    while (s > 0) {
        for (int i = n - 1; i >= 0; --i) {
            if (dp[s][i]) {
                mark[i] = 1;
                s -= a[i];
            }
        }
    }
    i64 l0 = 0, l1 = 0;
    for (int i = 0; i < n; ++i) {
        if (mark[i]) {
            cout << l1 << " \n"[i == n - 1];
            l1 += a[i];
        } else {
            cout << l0 << " \n"[i == n - 1];
            l0 += a[i];
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; T = 1;;
    while(T--) solve();
    return 0;
}
