#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void chmax(int& a, int b) {
    a = max(a, b);
}

void solve() {
    string s; cin >> s;
    int n = s.size();

    vector<vector<int>> dp (n + 1, vector<int> (2)); //dp[i][j] = max segmenrs prefix i can be split into, with the last segment of size = j + 1
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = dp[i - 1][1] + 1;
        if (i - 2 >= 0 and s[i - 1] != s[i - 2]) chmax(dp[i][0], dp[i - 1][0] + 1);
        if (i - 2 >= 0) dp[i][1] = dp[i - 2][0] + 1;
        if (i - 3 >= 0) {
            string cur = string () + s[i - 1] + s[i];
            string las = string () + s[i - 3] + s[i - 2];
            if (cur != las) chmax(dp[i][1], dp[i - 2][1]);
        } 
    }
    cout << max(dp[n][0], dp[n][1]) << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}

//an optimal division will never have a partition larger than size 2, any partition larger than 2 can be rearranged to in a way which will
//never decrease the answer, since we can always just pick segments of length 1 and 2 alternately
//with this fact we can define dp[i] = maximum segments the prefix i can be divided into, with max segments of length only two, the dp is linear
