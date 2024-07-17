#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    vector<int> c = {1, 5, 10, 25, 50};
    vector<i64> dp (30001);
    dp[0] = 1;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j <= 30000; ++j) {
            if (j - c[i] >= 0) dp[j] += dp[j - c[i]];
        }
    }
    int n; 
    while (cin >> n){
        if (dp[n] == 1) {
            cout << "There is only 1 way to produce " << n << " cents change.\n";
        } else {
            cout << "There are " << dp[n] << " ways to produce " << n << " cents change.\n";
        }
    }
    return 0;
}
