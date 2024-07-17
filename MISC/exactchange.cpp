#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int inf = 1e9;
void solve() {
    int x; cin >> x;
    int n; cin >> n;
    vector<i64> dp (20001, inf); //dp[i] = min coins to make i 
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        int c; cin >> c;
        for (int j = 20000 - c; j >= 0; --j) {
            dp[j + c] = min(dp[j + c], dp[j] + 1);
        }
    }
    while (dp[x] == inf) ++x;
    cout << x << ' ' << dp[x] << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
