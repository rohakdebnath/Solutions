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
    string s; cin >> s;
    i64 n = s.size();
    map<i64, i64> c;
    i64 sum = 0;
    mi ans = 0;
    c[0] = 1;
    for (i64 i = 0; i < n; ++i) {
        sum += 1 - 2 * (s[i] - '0');
        ans += c[sum] * (n - i);
        c[sum] += i + 2; 
    }   
    cout << i64(ans) << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    i64 T; cin >> T;
    while(T--) solve();
    return 0;
}
