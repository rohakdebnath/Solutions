#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int MOD = 1e9 + 7;  // Change as required
const int MAX = 1e5; // Maximum value of n required

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

vector<mi> fact(MAX+1, 1);

void precompute_factorials() {
    for (int i = 2; i <= MAX; ++i)
        fact[i] = fact[i-1] * i;
}

mi nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * inv(fact[r] * fact[n - r]);
}

vector<vector<mi>> f (5000 + 1, vector<mi> (5000 + 1));
void solve() {
    int n; cin >> n;
    mi ans = 0;
    for (int k = 1; k <= n; ++k) { //
        for (int j = 1; j <= k; ++j) { //a[k] being the jth largest mex
            if (k - 1 >= 0 and k - j >= 0 and n - k >= 0 and 2 * j - 1 - k >= 0 and 2 * j - 1 - k <= 5000) ans += k * f[k - 1][k - j] * f[n - k][2 * j - 1 - k];
        }
    }
    for (int k = n + 1 + (n % 2); k <= 2 * n + 1; ++k) {
        if (k % 2 == 0) continue;
        ans += k * f[n][k / 2];
    }
    cout << int(ans) << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    precompute_factorials();
    f[0][0] = 1;
    for (int i = 1; i <= 5000; ++i) {
        for (int j = 0; j <= 5000; ++j) {
            f[i][j] = nCr(i, j);
        }
    }
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
