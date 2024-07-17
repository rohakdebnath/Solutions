#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int MOD = 998244353;  // Change as required
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

vector<mi> fact(MAX+1, 1);

void precompute_factorials() {
    for (int i = 2; i <= MAX; ++i)
        fact[i] = fact[i-1] * i;
}

mi nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * inv(fact[r] * fact[n - r]);
}

void solve() {
    int n; cin >> n;
    vector<int> cx (n + 1);
    for (int i = 0; i < n; ++i) {
        int t; cin >> t;
        cx[i + 1] = cx[i] ^ t;
    }
    mi ans = 0;
    for (int i = 0; i < 30; ++i) {
        mi c[2] = {}, l[2] = {};
        for (int j = 0; j <= n; ++j) {
            int e = cx[j] >> i & 1;
            ans += (j * c[!e] - l[!e]) * (1 << i);
            c[e] += 1;
            l[e] += j;
        }
    }
    cout << int(ans) << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; T = 1;
    while(T--) solve();
    return 0;
}
