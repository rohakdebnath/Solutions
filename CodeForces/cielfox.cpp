#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
const int MOD = 1e9 + 7;  // Change as required
const int MAX = 1e7; // Maximum value of n required

struct mi {
    int v;
    explicit operator int() const { return v; }
    mi() { v = 0; }
    mi(long long _v) : v(_v % MOD) { v += (v < 0) * MOD; }
};

mi &operator+=(mi &a, mi b) {
    if ((a.v += b.v) >= MOD) a.v -= MOD;
    return a;
}

mi &operator-=(mi &a, mi b) {
    if ((a.v -= b.v) < 0) a.v += MOD;
    return a;
}

mi operator+(mi a, mi b) { return a += b; }
mi operator-(mi a, mi b) { return a -= b; }
mi operator*(mi a, mi b) { return mi((long long)a.v * b.v); }
mi &operator*=(mi &a, mi b) { return a = a * b; }

mi pow(mi a, long long p) {
    mi result = 1;
    while (p > 0) {
        if (p & 1) result *= a;
        a *= a;
        p >>= 1;
    }
    return result;
}

mi inv(mi a) {
    return pow(a, MOD - 2);
}
mi operator/(mi a, mi b) { return a * inv(b); }

void solve() {
    int n, k, d; cin >> n >> k >> d;
    vector<vector<mi>> dp (n + 1, vector<mi> (2)); //dp[i][j] = numbers of ways to make sum i when we have taken atleast one element worth >= d or not (j 0/1)
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            if (i - j < 0) break;
            if (j < d) {
                dp[i][0] += dp[i - j][0];
                dp[i][1] += dp[i - j][1];
            } else {
                dp[i][1] += dp[i - j][1] + dp[i - j][0];
            }
        }
    }
    cout << int(dp[n][1]) << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
