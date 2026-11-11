#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void chmax(i64& a, i64 b) {
    a = max(a, b);
}
const int inf = 1e9;
void solve() {
    int n, m; cin >> n >> m;
    vector<int> f (m + 1);
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        ++f[x];
    }
    // What to use as the state? If the number currently considered is x, the states related to x are only x-1, x-2.
    // If there are three identical straights, these three straights can be converted into three triplets, and the answer will not decrease.
    // Define dp[i][j][k] to represent that up to the ith number, the number of straights with i as the middle number and the end number are j and k respectively. j <= 2, k <= 2.
    // Why is there no state with i as the end? Because it will not affect the next state (which is at least i+1).

    vector<vector<i64>> dp (3, vector<i64> (3, -inf));
    dp[0][0] = 0;
    for (int i: f) {
        vector ndp = vector<vector<i64>> (3, vector<i64> (3));
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                for (int l = 0; l < 3; ++l) {
                    if (i - j - k - l >= 0) chmax(ndp[k][l], dp[j][k] + l + (i - j - k - l) / 3);
                }
            }
        }
        dp = ndp;
    }
    //the ans is dp[m][0][0] because there are no sequences with m + 1 or m + 2 as an element, so the other two parameters are as good as 0.
    cout << dp[0][0] << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
