#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int inf = 1e9;
void solve() {
    string s; cin >> s;
    int n = s.size();
    vector<vector<int>> dp (n + 1, vector<int> (n + 1)); //dp[i][j] = minimum number of palindrome segments for the range i..j
    vector<vector<int>> p (n + 1, vector<int> (n + 1)); //p[i][j] = if segment i..j is a palindrome or not

    for (int i = 0; i <= n; ++i) {
        p[i][i] = 1;
        for (int j = i + 1; j <= n; ++j) {
            dp[i][j] = inf;
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = i; j < n; ++j) {
            if (s[i] == s[j] and i != j) {
                p[i][j] = (i + 1 <= j - 1 ? p[i + 1][j - 1] : 1);
            }
            for (int k = i; k <= j; ++k) {
                if (p[i][k]) {
                    dp[i][j] = min(dp[i][j], (k != n - 1) + dp[k + 1][j]);
                }
            }
        }
    }
    cout << dp[0][n - 1] << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
