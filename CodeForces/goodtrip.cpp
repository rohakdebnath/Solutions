#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const i64 mod = 1e9 + 7;
const i64 maxn = 1e7;

struct mi {
    i64 v;
    explicit operator i64() const { return v; }
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
    for (i64 i = 2; i <= maxn; ++i)
        fct[i] = fct[i - 1] * i;
}

mi ncr(i64 n, i64 r) {
    if (r < 0 or r > n) return 0;
    return fct[n] * inv(fct[r] * fct[n - r]);
}

void solve() {
    i64 n, m, k; cin >> n >> m >> k;
    mi A = 0, B = 0;
    i64 d = n * (n - 1) / 2;
    mi y = inv(pw(d, k));
    for (i64 i = 0; i <= k; ++i) {
        A += y * i * ncr(k, i) * pw(d - 1, k - i);
        B += y * i * (i - 1) / 2 * ncr(k, i) * pw(d - 1, k - i);
    }
    mi ans = 0;
    for (i64 i = 0; i < m; ++i) { // sum from all other pairs is 0 so ignore them
        i64 a, b, f; cin >> a >> b >> f;
        ans += A * f + B;
    }
    cout << i64(ans) << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    prefact();
    i64 T; cin >> T;
    while(T--) solve();
    return 0;
}

//notes:
// let F(i) = sum from the ith pair, F(i) is probablistic, it can take different values based on the number of times ith pair is picked, if pair i is picked x times (x = [0..k]),  which (P of selecting ith pair x times out of k picks) comes with a probablity p = (k x) * 1 / n ^ x * (1 - 1 / n) ^ (k - x)
// F(i) = f(i) + f(i) + 1 + .. f(i) + x - 1 = xf(i) + (x 2);
// sum = sigma(F(i)) => E[sum] = sigma(E[F(i)])
// E[F(i)] = sigma[(xf(i) + (x 2)) * P(X = x)] = Af + B, f is independent of A and B so precalc A and B
