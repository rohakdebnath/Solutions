#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int mod = 1e9 + 7;
const int maxn = 1e7;

struct mi {
    int v;
    explicit operator int() const { return v; }
    mi() { v = 0; }
    mi(long long x) : v(x % mod) { v += (v < 0) * mod; }
};

mi& operator+=(mi& a, mi b) {
    if ((a.v += b.v) >= mod) a.v -= mod;
    return a;
}

mi& operator-=(mi& a, mi b) {
    if ((a.v -= b.v) < 0) a.v += mod;
    return a;
}

mi operator+(mi a, mi b) { return a += b; }
mi operator-(mi a, mi b) { return a -= b; }
mi operator*(mi a, mi b) { return mi((long long)a.v * b.v); }
mi& operator*=(mi& a, mi b) { return a = a * b; }

mi pw(mi a, long long p) {
    mi res = 1;
    while (p > 0) {
        if (p & 1) res *= a;
        a *= a;
        p >>= 1;
    }
    return res;
}

mi inv(mi a) {
    return pw(a, mod - 2);
}
mi operator/(mi a, mi b) { return a * inv(b); }

vector<mi> fct(maxn + 1, 1);

void prefact() {
    for (int i = 2; i <= maxn; ++i)
        fct[i] = fct[i - 1] * i;
}

mi ncr(int n, int r) {
    if (r < 0 or r > n) return 0;
    return fct[n] * inv(fct[r] * fct[n - r]);
}

void solve() {
    int n, k; cin >> n >> k;
    vector<vector<mi>> dp(n + 1, vector<mi>(k + 1)); //dp[i][j] = # of perms with i elements and <= j inversions, also define exact[i][j] = exac j inversions in i length perm, dp[i][j] is sum of exact[i][t] t ranges from 0 to j
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j]; //dp[i][j] = dp[i][j - 1] + (all possible exact[i - 1][j - x]) where x is all the extra inversions we can obtain from placing element = i. second term adds all exact[i][t] t ranges from 0 to j (definition of our dp)
            if (j >= i) dp[i][j] = dp[i][j] - dp[i - 1][j - i]; //but we only need the exact from j - (i - 1) to j, since we cannot obtain more than i - 1 inversions by placing element = i on a perm of length i - 1. hence subtract dp[i - 1][j - i] to remove all exacts below what we can obtain
        }
    }
    cout << int(dp[n][k] - dp[n][k - 1]) << '\n'; 
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
