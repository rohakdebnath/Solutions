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

void solve(int t) {
    int n; cin >> n;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    mi m = 0, M = 0;
    for (int i = 0; i < n; ++i) {
        M += a[i] * mi(1) / pw(2, n - i);
        m += a[i] * mi(1) / pw(2, i + 1);
    }
    cout << "Case #" << t << ": " << int((M - m) * pw(2, n)) << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    for (int i = 1; i <= T; ++i) {
        solve(i);
    }
    return 0;
}
