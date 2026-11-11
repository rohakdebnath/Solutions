#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int inf = 1e9;
void solve() {
    int n, h, l, r; cin >> n >> h >> l >> r;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    vector<vector<int>> dp (n + 1, vector<int> (h, -inf)); 
    //dp[i][j] = max good sleeps if we finished sleeping the ith sleep at hour j, -inf if you cant end sleeping at the jth hour
    dp[0][0] = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < h; ++j) {
            int x = ((j - a[i]) % h + h) % h;
            int y = ((j - a[i] + 1) % h + h) % h;
            dp[i + 1][j] = max({dp[i + 1][j], dp[i][x] + (j <= r and l <= j), dp[i][y] + (j <= r and l <= j)});
        }
    }
    cout << *max_element(dp[n].begin(), dp[n].end()) << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
