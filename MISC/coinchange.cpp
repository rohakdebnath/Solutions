#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    vector<int> c = {1, 5, 10, 25, 50};
    vector<int> dp (7490); //dp[i] = number of ways to make i coins, take any coin any number of time, 1 1 2 and 1 2 1 are same though;
    dp[0] = 1;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 7490; ++j) {
            if (j - c[i] >= 0) dp[j] += dp[j - c[i]];
        }
    }
    int q;
    while (cin >> q){
        cout << dp[q] << '\n';
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; T = 1;
    while(T--) solve();
    return 0;
}
