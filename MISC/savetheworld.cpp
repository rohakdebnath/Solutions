#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

int main()
{
    UNSYNC
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        string str1, str2; cin >> str1 >> str2;
        vector<vector<int>> dp (n, vector<int> (m));
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; j++){   
                if (i == 0 && j == 0) dp[i][j] = 0;
                else if (i == 0) dp[i][j] = dp[i][j - 1] + 1;
                else if (j == 0) dp[i][j] = dp[i - 1][j] + 1;
                else dp[i][j] = min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + (str1[i] != str2[j])});
            }
        }
        cout << dp[n - 1][m - 1] << '\n';
    }
    return 0;
}
