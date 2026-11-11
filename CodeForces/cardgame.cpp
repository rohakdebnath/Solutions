#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int mod = 998244353;
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
    int n, m; cin >> n >> m;
    vector dp (n + 1, vector<mi> (m + 1)); // dp[i][j] = number of ways to distribute first i suits and we have j unmatched cards of type 1
    vector f (m + 1, vector<mi> (m + 1)); //f[i][j] = number of ways to end a bracket sequence with i cards and balance = j
    f[0][0] = 1;
    for (int i = 1; i <= m; ++i) {
        for (int j = 0; j <= i; ++j) {
            f[i][j] += (j + 1 <= i) * f[i - 1][j + 1] + (j - 1 >= 0) * f[i - 1][j - 1];
        }
    }
    for (int i = 0; i <= m; ++i) {
        dp[1][i] = f[m][i];
    }
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            for (int k = 0; k <= j; ++k) {
                dp[i][j - k] += dp[i - 1][j] * f[m][k];
            }
        }
    }
    cout << int(dp[n][0]) << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
//A wins when each card of A has a unique mapping to B such that the suit of (A[i].suit = 1 and B[i].suit > 1) or (A[i].suit == B[i].suit and A[i].rank > B[i].rank)

