#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int inf = 1e9;
void solve() {
    int n; cin >> n;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> dp (3, -inf); //dp[i][j] = max points till ith index if we have 0: not skipped elements yet, 1: skipping, 2: finished skipping elements
    dp[0] = 0;

    for (int i = 0; i < n; ++i) {
        dp[2] = max(dp[1], dp[2]);
        dp[1] = max(dp[1], dp[0]);

        if (a[i] > dp[0]) ++dp[0];
        else if (a[i] < dp[0]) --dp[0];

        
        if (a[i] > dp[2]) ++dp[2];
        else if (a[i] < dp[2]) --dp[2];
    }

    cout << max(dp[1], dp[2]) << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; 
    while(T--) solve();
    return 0;
}
