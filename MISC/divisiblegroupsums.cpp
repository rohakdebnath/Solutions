#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve(int n, int q) {
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];

    //dp[i][j][k] = number of subsets of size j till ith element with remainder k when divided by m. i can go till n - 1, j can go till m and k can go till d - 1
    //transitions: dp[i][j][k] += dp[i - 1][j][k] + dp[i - 1][j - 1][((k - a[i]) % d + d) % d]
    auto f = [&] (int m, int d) {
        vector<vector<i64>> dp (m + 1, vector<i64> (d)); //space saving dp
        dp[0][0] = 1;
        for (int i = 0; i < n; ++i) {
            auto ndp = dp;
            for (int j = 1; j <= m; ++j) {
                for (int k = 0; k < d; ++k) {
                    int t = ((k - a[i]) % d + d) % d;
                    ndp[j][k] += dp[j - 1][t];
                }
            }
            dp = ndp;
        }
        cout << dp[m][0] << '\n';
    };
    for (int i = 0; i < q; ++i) {
        int d, m; cin >> d >> m;
        cout << "QUERY " << i + 1 << ": ";
        f(m, d);       
    } 
    
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    while (true) {
        int a, b; cin >> a >> b;
        if (!a and !b) break;
        int x = 1;
        cout << "SET " << x << ":\n";
        ++x;
        solve (a, b);
    }
    return 0;
}
