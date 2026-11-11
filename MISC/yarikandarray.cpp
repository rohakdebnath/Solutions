#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int inf = 1e9;
void solve() {
    int n; cin >> n;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> dp (n + 1, -inf); //dp[i] = max sum of alt par subarray ending at i

    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        dp[i + 1] = a[i] + max(0, (i > 0 and (abs(a[i]) % 2) ^ (abs(a[i - 1]) % 2) ? dp[i]: 0));
    }
    cout << *max_element(dp.begin() + 1, dp.end()) << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
