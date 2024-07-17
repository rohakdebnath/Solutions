#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve(int n, int m) {
    int u = m; 
    u += (u > 1800 ? 200 : 0);
    vector<int> dp (u + 1, -1); //dp[i] = maximum pts that can be made with i cost, -1 means cant make
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        int p, f; cin >> p >> f;
        for (int j = u; j >= p; --j) {
            dp[j] = max(dp[j], dp[j - p] + f);
        }
    }
    int maxF = 0;
    if (m > 1800 and m <= 2000) {
        maxF = *max_element(dp.begin(), dp.begin() + m);
        for (int j = 2001; j <= u; ++j) maxF = max(maxF, dp[j]);
    } else {
        maxF = *max_element(dp.begin(), dp.end());
    }
    cout << maxF << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m;
    while (cin >> n >> m) solve(m, n);
    return 0;
}

