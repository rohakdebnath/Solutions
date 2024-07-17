#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int MOD = 1e6;
signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    vector<vector<int>> dp (101, vector<int> (101)); //dp[n][k] = sumover:x (0 to n) (dp[n - x][k - 1]), ways to make n with k numbers
    auto solve = [&] (int n, int k) {//push the ways of making smaller sums into bigger sums
        for (int i = 0; i <= n; ++i) {
            dp[i][1] = 1;
        } 
        for (int i = 0; i <= n; ++i) { //sum i
            for (int j = 1; j < n; ++j) { //j elements
                for (int k = 0; k <= n - i; ++k) { //spread to sum i + k
                    dp[i + k][j + 1] = (dp[i + k][j + 1] + dp[i][j]) % MOD; 
                }
            }
        }
    };
    solve(100, 100);
    while(true) {
        int a, b; cin >> a >> b;
        if (a and b) cout << dp[a][b] << '\n';
        else break;
    } 
    return 0;
}
