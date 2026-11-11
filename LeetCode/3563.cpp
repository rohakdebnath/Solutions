#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = n - 2; i >= 0; i--) {
        for (int j = i + 1; j < n; j += 2) {
            for (int k = i + 1; k <= j; k += 2) {
                if (abs(s[i] - s[k]) == 1 or abs(s[i] - s[k]) == 25) {
                    if ((i + 1 > k - 1 or dp[i + 1][k - 1]) && (k + 1 > j or dp[k + 1][j])) dp[i][j] = 1;
                }
            }
        }
    }
    vector<string> ans(n + 1, string() + (char('z' + 1)));
    ans[n] = "";
    for (int i = n - 1; i >= 0; --i) {
        for (int j = i; j < n; ++j) {
            if (j - 1 < i or dp[i][j - 1]) {
                ans[i] = min(ans[i], (string() + s[j]) + ans[j + 1]);
            }
        }
        ans[i] = min(ans[i], dp[i][n - 1] ? "" : s.substr(i));
    }
    cout << ans[0] << endl;
    return 0;
}
