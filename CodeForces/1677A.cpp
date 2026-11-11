#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<int> p (n); for (int i = 0; i < n; ++i) cin >> p[i];
    i64 ans = 0;
    vector<vector<i64>> inv (n + 1, vector<i64> (n + 1));
    for (int i = 0; i < n; ++i) { //create a difference array
        for (int j = i + 1; j < n; ++j) {
            if (p[i] > p[j]) { //all the subarrays st: r <= i and c >= j should be +1 in the difference array
                ++inv[0][j];
                --inv[i + 1][j];
            }
        }
    }
    for (int i = 0; i < n; ++i) { //prefix summing the difference array
        for (int j = 0; j < n; ++j) {
            if (i > 0) inv[i][j] += inv[i - 1][j];
            if (j > 0) inv[i][j] += inv[i][j - 1];
            if (i * j > 0) inv[i][j] -= inv[i - 1][j - 1];
        }
    }
    //fix a < c st p[a] < p[c], then add inv[a + 1, n - 1] - inv[a + 1, c] - inv[c, n - 1];
    for (int a = 0; a < n; ++a) {
        for (int c = a + 2; c < n; ++c) {
            if (p[a] < p[c]) {
                ans += inv[a + 1][n - 1] - inv[a + 1][c] - inv[c][n - 1];
            }
        }
    }
    cout << ans << '\n';

}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
