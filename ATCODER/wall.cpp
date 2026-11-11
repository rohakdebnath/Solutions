#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int h, w; cin >> h >> w;
    vector<vector<int>> dp (10, vector<int> (10));
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            cin >> dp[i][j];
        }
    }
    for (int k = 0; k < 10; k++){
        for (int i = 0; i < 10; i++){
            for (int j = 0; j < 10; j++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            int x; cin >> x;
            if (x != -1) {
                ans += dp[x][1];
            }
        }
    }
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
