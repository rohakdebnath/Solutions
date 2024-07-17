#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int inf = 1e9;
void solve() {
    int n, x; cin >> n >> x;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> dp (x + 1, inf); //dp[i] = min coins used to make i
    dp[0] = 0;
    for (int i = 0; i < x + 1; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[j] + i <= x) dp[i + a[j]] = min(dp[i + a[j]], dp[i] + 1);
        }
    }
    cout << (dp[x] == inf ? -1 : dp[x]) << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; T = 1;
    while(T--) solve();
    return 0;
}
