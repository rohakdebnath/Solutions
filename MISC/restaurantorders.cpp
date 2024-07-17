#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    vector<vector<i64>> dp (30000 + 1, vector<i64> (n + 1)); //dp[j][i] = count of ways in wwhich sum j can be made using ith element in it, otherwise 0, dp[j][n] means total ways in which it can be made
    dp[0][n] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= 30000; ++j) {
            if (j - a[i] >= 0) dp[j][i] += dp[j - a[i]][n];
            dp[j][n] += dp[j][i];
        }
    }
    int Q; cin >> Q;
    for (int _ = 0; _ < Q; ++_) {
        int q; cin >> q;
        if (dp[q][n] == 0) {
            cout << "Impossible\n";
        } else if (dp[q][n] > 1) {
            cout << "Ambiguous\n";
        } else {
            int i = n - 1;
            vector<int> mark;
            while (q > 0) {
                while (dp[q][i]) {
                    mark.push_back(i + 1);
                    q -= a[i];
                }
                --i;
            }
            sort(mark.begin(), mark.end());
            for (int x: mark) cout << x << ' ';
            cout << '\n';
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; T = 1;
    while(T--) solve();
    return 0;
}
