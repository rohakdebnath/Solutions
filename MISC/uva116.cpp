#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const i64 inf = 2e18;
void solve(int n, int m) {
    vector<vector<int>> grid(n, vector<int> (m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
    vector<vector<i64>> next (n, vector<i64> (m, inf)), dp (n, vector<i64> (m, inf));//next[i][j] = value of previous row which leads here in the minimum path
    for (int i = 0; i < n; ++i) { //base case
        dp[i][0] = grid[i][0];
    }
    //dp[i][j] = shortest value of any path to reach i, j
    for (int i = 0; i + 1 < m; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k : {-1, 0, 1}) {
                i64& x = dp[(j + k + n) % n][i + 1];
                if ((grid[(j + k + n) % n][i + 1] + dp[j][i] < x) or ((grid[(j + k + n) % n][i + 1] + dp[j][i] == x) and (next[j][i] > (j + k + n) % n))) {
                    x = grid[(j + k + n) % n][i + 1] + dp[j][i];
                    next[j][i] = (j + k + n) % n;
                }
            }
        }
    }
    vector<int> s (m);
    i64 ans = inf;
    for (int i = 0; i < n; ++i) {
        ans = min(ans, dp[i][m - 1]);
    }
    for (int i = 0; i < n; ++i) {
        int t = 0;
        vector<int> l (m);
        int k = i;
        for (int j = 0; j < m; ++j) {
            t += grid[i][j];
            l[j] = k;
            k = next[k][j];
        }
        if (t == ans) {
            s = l;
            break;
        }
    }

    for (int i = 0; i < m; ++i) {
        cout << s[i] + 1 << " \n"[i == m - 1];
    }
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m;
    while (cin >> n >> m) {
        solve(n, m);
    }
    return 0;
}
