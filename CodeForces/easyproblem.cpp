#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int inf = 1e9;
void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];

    vector<vector<i64>> dp (n + 1, vector<i64> (4)); //dp[i][j] = minimum cost to match exactly first j characters from hard in the prefix i (i.e match exactly '' or 'h' or 'ha' or 'har' with the prefix i of s)
    dp[0] = vector<i64> (4, inf); dp[0][0] = 0;

    for (int i = 0; i < n; ++i) {
        if (s[i] == 'h') {
            dp[i + 1][0] = dp[i][0] + a[i];
            dp[i + 1][1] = min(dp[i][1], dp[i][0]);
            dp[i + 1][2] = dp[i][2];
            dp[i + 1][3] = dp[i][3];
        } else if (s[i] == 'a') {
            dp[i + 1][0] = dp[i][0];
            dp[i + 1][1] = dp[i][1] + a[i];
            dp[i + 1][2] = min(dp[i][2], dp[i][1]);
            dp[i + 1][3] = dp[i][3];
        } else if (s[i] == 'r') {
            dp[i + 1][0] = dp[i][0];
            dp[i + 1][1] = dp[i][1];
            dp[i + 1][2] = dp[i][2] + a[i];
            dp[i + 1][3] = min(dp[i][3], dp[i][2]);
        } else if (s[i] == 'd') {
            dp[i + 1][0] = dp[i][0];
            dp[i + 1][1] = dp[i][1];
            dp[i + 1][2] = dp[i][2];
            dp[i + 1][3] = dp[i][3] + a[i];
        } else {
            dp[i + 1] = dp[i];
        }

        cout << *min_element(dp[n].begin(), dp[n].end()) << '\n';
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
