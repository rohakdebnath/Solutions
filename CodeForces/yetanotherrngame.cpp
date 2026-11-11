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
    i64 n; cin >> n;
    vector<i64> a (n); for (i64 i = 0; i < n; ++i) cin >> a[i];

    vector<array<i64, 2>> s;
    mi ans = 0;
    for (i64 i = 0; i < n; ++i) {
        i64 x = a[i];
        i64 y = __builtin_ctz(a[i]);
        x >>= y;
        while (!s.empty() and (y > 30 or (x << y) > s.back()[0])) {
            auto [l, m] = s.back();
            s.pop_back();
            ans += (l - l * pw(2, m));
            y += m;
        }
        ans += x * pw(2, y);
        cout << i64(ans) << " \n"[i == n - 1];
        s.push_back({x, y});
    } 
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    i64 T; cin >> T;
    while(T--) solve();
    return 0;
}
