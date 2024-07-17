#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> dp (n); //dp[i] = max difference in score we can create for subarray [0...i];
    for (int i = n - 2; i >= 0; --i) {
        int s = a[i];
        for (int j = i + 1; j < n; ++j) {
            s += a[j];
            dp[j] = max(s - a[i] - dp[j], s - a[j] - dp[j - 1]);
        }
    }
    cout << dp[n - 1] << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; T = 1;
    while(T--) solve();
    return 0;
}
