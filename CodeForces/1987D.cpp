#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int inf = 1e9;
void solve() {
    int n; cin >> n;
    vector<int> f (n + 1);
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        ++f[x];
    }
    f.erase(remove(f.begin(), f.end(), 0), f.end()); 
    n = f.size();
    vector<int> dp (n + 1, inf); //dp[i][j] = minimum sum of a subset of (1..i) with j elements such that sum(f[p]) <= i - p for all p 1 <= p <= j
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        auto ndp = dp;
        for (int j = 0; j < n; ++j) {
            if (dp[j] + f[i] <= i - j) ndp[j + 1] = min(ndp[j + 1], dp[j] + f[i]);
        }
        dp = ndp;
    }
    int y = n;
    while (dp[y] == inf) --y;
    cout << n - y << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
