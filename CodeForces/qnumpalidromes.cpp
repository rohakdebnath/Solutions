#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    string s; cin >> s;
    int n = s.size();
    vector<vector<int>> dp (n, vector<int> (n)); //dp[i][j] = number of palindromes in i..j
    vector<vector<bool>> p (n, vector<bool> (n)); //if substring i..j is palindrome
    
    for (int i = n - 1; i >= 0; --i) {
        dp[i][i] = p[i][i] = 1;
        for (int j = i + 1; j < n; ++j) {
            p[i][j] = (s[i] == s[j]) and (p[i + 1][j - 1] or (j - i == 1));
            dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1] + p[i][j];
        }
    }
    int q; cin >> q;
    while(q--) {
        int l, r; cin >> l >> r; --l , --r;
        cout << dp[l][r] << '\n';
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
