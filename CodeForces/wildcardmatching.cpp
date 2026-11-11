#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector dp (n + 1, vector<i64> (m + 1)); //dp[i][j] = number of ways to match prefix i and j of the respective strings
        dp[0][0] = 1;
        int j = 0;
        while (p[j] == '*') {
            for (int i = 0; i <= n; ++i) {
                dp[i][j + 1] = dp[i][j];
            }
            ++j;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (p[j] == '?' or s[i] == p[j]) dp[i + 1][j + 1] += dp[i][j];
                if (p[j] == '*') dp[i + 1][j + 1] += dp[i][j + 1] + dp[i + 1][j];
                dp[i + 1][j + 1] %= 1000000007;
            }
        }
        return dp[n][m] > 0;
    }
};

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    Solution s; 
    cout << s.isMatch("", "*") << '\n';
    return 0;
}
