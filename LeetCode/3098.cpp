#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

class Solution {
public:
    int sumOfPowers(vector<int>& a, int k) {
        int n = a.size();
        vector<int> d;
        sort(d.begin(), d.end());
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                
            }
        }
        vector<vector<vector<int>>> dp (n, vector<vector<int>> (k + 1, vector<int> (n))); //dp[i][j][k] = count of elements with length j till i such that last picked element was at k

    }
};

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    return 0;
}

//abcabcabcabc [abc, 3]
//bcabca [bca, 2]
