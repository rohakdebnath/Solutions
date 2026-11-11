//slight change in statement, can only remove when alteast one of each kind of x - 1 and. x + 1 is removed
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int inf = 10 + 1;
void solve() {
    int n; cin >> n;
    vector<i64> f (inf);
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        f[x] = 1;
    }
    vector<vector<i64>> dp (inf, vector<i64> (2)); //dp[i][j] = max pts when value i is picked or not
    for (int i = 1; i < inf; ++i) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        if (f[i - 1] and f[i + 1] and i + 1 < inf and i - 1 >= 0) dp[i][1] = i + (i - 3 >= 0 ? max(dp[i - 3][0], dp[i - 3][1]) : 0);
    }
    cout << max(dp[inf - 1][0], dp[inf - 1][1]) << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
