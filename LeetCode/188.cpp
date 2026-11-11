#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int inf = 1e9;
class Solution {
public:
    int maxProfit(int k, vector<int>& a) {
        int n = a.size();
        vector dp (k + 1, 0); //dp[j] = max profit till ith index if we have used up j transactions till now
        vector f (k + 1, -inf); //f[j] = max value of (dp[j - 1] - a[i]) till ith iteration

        for (int i = 1; i <= n; ++i) {
            vector ndp = dp; 
            for (int l = 1; l <= k; ++l) {
                f[l] = max(f[l], dp[l - 1] - a[i - 1]);
                ndp[l] = max(ndp[l], f[l] + a[i - 1]);
            }
            dp = std::move(ndp);
        }
        return *max_element(dp.begin(), dp.end());
    }
};

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    return 0;
}
