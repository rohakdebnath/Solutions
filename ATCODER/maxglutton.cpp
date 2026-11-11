//practice for swap trick in dp (applicable when the value is significanty more bounded that the key range, swapping them will reduce complexity)
//famous example can be the LIS algorithm, LCS for string of size <= 5000 and <= 1e6 cant be done normally but redefining dp[i][j] = 
//leftmost matching index of string a with string b (<= 1e6) amongst the first i index of a and matching exactly j elements. Useful because the LCS length (j) is bounded by the minimum of the length of the two strings
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int inf = 1e9;
void solve() {
    int n, x, y; cin >> n >> x >> y;
    vector<int> a (n), b (n); 
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    vector<vector<i64>> dp (n + 1, vector<i64> (x + 1, inf)); //dp[i][j][k] = smallest value of saltiness using the first i elements (picking exactly j dishes from them) and sweetness exactly k
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j >= 1; --j) {
            for (int k = x; k >= a[i]; --k) {
                dp[j][k] = min(dp[j][k], dp[j - 1][k - a[i]] + b[i]);
            }
        }
    }
    for (int i = n; i >= 0; --i) {
        for (int j = 0; j <= x; ++j) {
            if (dp[i][j] <= y) {
                cout << min(n, i + 1) << '\n';
                return;
            }
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
//answer is: from dp[n][j][k], find the largest value of j for which the dp is <= y for any k. ans is min(j + 1, n), since bro can eat one more dish than when sweet, salt <= x, y
