#include <bits/stdc++.h>

using namespace std;
 
using i64 = long long;
const int mod = 1e9 + 7;
class Solution {
public:
    i64 countRoutes(vector<i64>& a, i64 s, i64 e, i64 fuel) {
        i64 n = a.size();
        vector<vector<i64>> dp (n, vector<i64> (fuel, -1));
        //dp[i][j] = number of ways to reach state i with j fuel left
        auto dfs = [&] (auto&& self, i64 i, i64 f) {
            if (dp[i][f] != -1) return dp[i][f];
            i64 ways = (i == e) ? 1 : 0;
            for (i64 l = 0; l < n; ++l) {
                if (l != i and f >= abs(a[l] - a[i])) ways = (ways + self(self, l, f - abs(a[l] - a[i]))) % mod;
            }

            return dp[i][f] = ways;
        };

        for (i64 i = 0; i < n; ++i) {
            for (i64 j = 0; j <= fuel; ++j) {
                if (dp[i][j] == -1) dfs(dfs, i, j);
            }
        }

        i64 ans = 0;
        for (i64 i = 0; i <= fuel; ++i) {
            (ans += dp[n - 1][i]) %= mod;
        }

        return ans;
    }
};

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    return 0;
}
