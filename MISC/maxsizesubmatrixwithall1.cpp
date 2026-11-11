#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int inf = 1e9;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> grid(n + 2, vector<int>(m + 2, 0));

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cin >> grid[i][j];
        }
    }
    
    vector<vector<int>> g(n + 2, vector<int>(m + 1, 0));
    for(int i = n; i >= 1; --i){
        for(int j = 1; j <= m; ++j){
            if(grid[i][j] == 1){
                g[i][j] = 1 + g[i + 1][j];
            }
            else{
                g[i][j] = 0;
            }
        }
    }
    
    vector<vector<int>> h(n + 1, vector<int>(m + 2, 0));
    for(int i = 1; i <= n; ++i){
        for(int j = m; j >= 1; --j){
            if(grid[i][j] == 1){
                h[i][j] = 1 + h[i][j + 1];
            }
            else{
                h[i][j] = 0;
            }
        }
    }

    int ans = -inf;
    
    for (int i = 1; i <= n; ++i) {         
        vector<int> dp (m + 1); //dp[j] = max sum of cons same segment ending at i
        dp[1] = g[i][1];
        for (int j = 2; j <= m; ++j) {
            dp[j] = g[i][j];
            if (g[i][j] == g[i][j - 1]) dp[j] += dp[j - 1];
        }
        ans = max(ans, *max_element(dp.begin(), dp.end()));
    }
    
    for (int j = 1; j <= m; ++j) {
        vector<int> dp (n + 1); //dp[j] = max sum of cons same segment ending at i
        dp[1] = h[1][j];
        for (int i = 2; i <= n; ++i) {
            dp[i] = h[i][j];
            if (h[i][j] == h[i - 1][j]) dp[i] += dp[i - 1];
        }
        ans = max(ans, *max_element(dp.begin(), dp.end()));
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
