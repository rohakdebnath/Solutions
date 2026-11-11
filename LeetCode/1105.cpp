#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int inf = 1e9;
class Solution {
public:        
    int minHeightShelves(vector<vector<int>>& books, int w) {
        int n = books.size();
        vector<int> dp (n + 1, inf); // dp[i] = min height if we start placing elements from the ith book
        dp[n] = 0;
        for (int i = n - 1; i >= 0; --i) {
            int d = 0, h = 0;
            for (int j = i; j < n; ++j) {
                d += books[j][0];
                if (d > w) break;
                h = max(h, books[j][1]);
                dp[i] = min(dp[i], h + dp[j + 1]);
            }
        }
        return dp[0];
    }
};

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    return 0;
}

