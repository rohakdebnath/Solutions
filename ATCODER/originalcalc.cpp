#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int mod = 1e5;
void solve() {
    i64 n, k; cin >> n >> k;
    auto digsum = [&] (int x) {
        int sum = 0;
        while (x) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    };
    vector<vector<int>> dp (63, vector<int> (mod + 1));
    for (int i = 0; i <= mod; ++i) {
        dp[0][i] = (i + digsum(i)) % mod;
    }

    for (int i = 1; i < 63; ++i) {
        for (int j = 0; j <= mod; ++j) {
            dp[i][j] = dp[i - 1][dp[i - 1][j]];
        }
    }
    for (int i = 0; i < 63; ++i) {
        if (((1LL << i) & k) == 0) continue;
        n = dp[i][n];
    }
    cout << n << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
