#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const i64 inf = 1e9;
const string z = "narek";
void solve() {
    i64 n, m; cin >> n >> m;
    vector<string> s (n);
    for (i64 i = 0; i < n; ++i) {
        cin >> s[i];
    }

    vector<vector<i64>> dp (n + 1, vector<i64> (5, -inf)); //dp[i][j] = maximum scoren - scorec till the ith string and ending the search at exactly j characters out of "narek"
    dp[0][0] = 0;

    for (i64 i = 0; i < n; ++i) {
        for (i64 j = 0; j < 5; ++j) {
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            i64 x = j;
            i64 seg = 0;
            for (i64 k = 0; k < m; ++k) {
                if (s[i][k] == z[x]) {
                    ++x;
                }
                if (x == 5) {
                    ++seg;
                    x = 0;
                }
            }
            i64 val = 10LL * seg - accumulate(s[i].begin(), s[i].end(), 0LL, [&] (i64 s, char c) {return s + (z.find(c) != string::npos);});
            dp[i + 1][x] = max(dp[i + 1][x], dp[i][j] + val);
        }
    }

    cout << *max_element(dp[n].begin(), dp[n].end()) << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    i64 T; cin >> T;
    while(T--) solve();
    return 0;
}

