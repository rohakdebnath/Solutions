#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, k; cin >> n >> k;
    vector<i64> a (n); for (int i = 0; i < n; ++i) cin >> a[i];

    //dp[i][j] = if using first i elements j partitions can be made where each partition is a supermask of s
    auto check = [&] (i64 s) -> bool{
        vector<vector<int>> dp (n + 1, vector<int> (k + 1, false)); 
        dp[0][0] = true;
        for (int i = 0; i < n; ++i) {
            i64 sum = 0;
            for (int j = i; j >= 0; --j) {
                sum += a[j];
                if ((sum & s) == s) {
                    for (int l = 0; l < k; ++l) {
                        dp[i + 1][l + 1] |= dp[j][l];
                    }
                }
            }
        }
        return dp[n][k];
    };
    i64 s = 0;
    for (int i = 56; i >= 0; --i) {
        if (check(s | (1LL << i))) {
            s |= (1LL << i);
        }
    }
    cout << s << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}

//dp[i][j] = 
