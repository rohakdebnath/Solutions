#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    string a, b; cin >> a >> b;
    int s = a.size(), t = b.size();
    vector<vector<int>> dp (s + 1, vector<int> (t + 1)); //dp[i][j] length of the longest b consequtive, a subsequential string in the prefixes i and j, which also ends at i and j
    int m = 0;
    for (int i = 1; i <= s; ++i){
        for (int j = 1; j <= t; ++j) {
            if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = dp[i - 1][j];
            m = max(m, dp[i][j]);
        }
    }
    cout << s + t - m << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}


