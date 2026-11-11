#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const i64 MOD = 1e9 + 7;  // Change as required
const i64 MAX = 1e7; // Maximum value of n required

struct mi {
    i64 v;
    explicit operator i64() const { return v; }
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
    for (i64 i = 2; i <= MAX; ++i)
        fact[i] = fact[i-1] * i;
}

mi nCr(i64 n, i64 r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * inv(fact[r] * fact[n - r]);
}

void solve() {
    i64 n; cin >> n;
    vector<i64> a (n); for (i64 i = 0; i < n; ++i) cin >> a[i];

    mi ans = 0;
    for (i64 b = 0; b < 60; ++b) {
        array<i64, 2> on {};
        for (i64 i = 0; i < n; ++i) {
            ++on[a[i] >> b & 1];
        }
        ans += mi(1) * (1LL << b) * on[0] * on[1];
    }
    cout << i64(ans) << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
