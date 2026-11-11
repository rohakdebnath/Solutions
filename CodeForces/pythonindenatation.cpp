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
    int n; cin >> n;
    vector<char> a (n); for (int i = 0; i < n; ++i) cin >> a[i];

    vector<vector<mi>> dp (n + 1, vector<mi> (n)); //dp[i][j] = number of ways in which the ith character is placed at indentation level j
    //f to f: must start at 1 + the previous f's indentation level
    //f to s: must start at 1 + the previous f's indentation level
    //s to f: can start from 0 to the previous s's indentation level
    //s to s: can start from 0 to the previous s's indentation level, => do a push dp
    dp[1][0] = 1;
    for (int i = 0; i < n; ++i) {
        vector<mi> p (n);
        for (int j = 0; j < i; ++j) { //previous states indentation level
            if (a[i] == 's' and a[i - 1] == 'f') {
                dp[i + 1][j + 1] += dp[i][j];
            } else if (a[i] == 'f' and a[i - 1] == 'f') {
                dp[i + 1][j + 1] += dp[i][j];
            } else {
                p[0] += dp[i][j];
                p[j + 1] -= dp[i][j];
            }
        }
        partial_sum(p.begin(), p.end(), p.begin());
        for (int j = 0; j < n; ++j) {
            dp[i + 1][j] += p[j];
        }
    }
    mi w = 0;
    for (int i = 0; i < n; ++i) {
        w += dp[n][i];
    }
    cout << int(w) << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
