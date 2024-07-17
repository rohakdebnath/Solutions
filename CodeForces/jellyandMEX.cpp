#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const i64 Z = 5001;
void solve() {
    int n; cin >> n;
    int MEX = 5000;
    vector<i64> f (Z);
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        if (x <= MEX) ++f[x];
    }
    for (int i = 0; i < Z; ++i) {
        if (!f[i]){
            MEX = i;
            break;
        }
    }
    vector<i64> dp (MEX + 1, 2e18); //dp[i] = when the MEX is i, the minimum value of m. For calcing dp[i] we need to know evrything about higher (j > i) states so calc from high to low
    dp[MEX] = 0;
    for (int i = MEX; i >= 0; --i) {
        for (int j = 0; j < i; ++j) {
            dp[j] = min(dp[j], dp[i] + (f[j] - 1) * i + j);
        }
    }
    cout << dp[0] << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
