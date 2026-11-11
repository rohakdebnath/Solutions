//Credits: shayan's video explanation
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int inf = 1e9;
const int s = 30, d = 50;
vector<vector<vector<int>>> dp (s + 1, vector<vector<int>> (s + 1, vector<int> (d + 1, inf)));
//dp[i][j][k] = lowest cost to eat k pieces from a bar of dimension i x j
void solve() {
    int r, c, k; cin >> r >> c >> k;
    cout << dp[r][c][k] << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    for (int i = 0; i <= s; ++i) {
        for (int j = 0; j <= s; ++j) {
            dp[i][j][0] = 0;
            if (i * j <= 50) dp[i][j][i * j] = 0;
        }
    }

    for (int i = 1; i <= s; ++i) {
        for (int j = 1; j <= s; ++j) {
            for (int k = 0; k <= d; ++k) {
                // cut the i x j bar then split the pieces you want to eat from each section separately, do it for both horizontal and vertical cuts
                for (int h = 1; h < i; ++h) {
                    for (int p = 0; p <= k; ++p) {
                        dp[i][j][k] = min(dp[i][j][k], dp[h][j][p] + dp[i - h][j][k - p] + j * j);
                    }
                }
                for (int v = 1; v < j; ++v) {
                    for (int p = 0; p <= k; ++p) {
                        dp[i][j][k] = min(dp[i][j][k], dp[i][v][p] + dp[i][j - v][k - p] + i * i);
                    }
                }
            }
        }
    }
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
