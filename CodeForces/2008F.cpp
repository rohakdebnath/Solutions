#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int MOD = 1e9 + 7;
const int MAX = 1e7;

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

__int128 gcd(__int128 a, __int128 b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

void solve() {
    int n;
    cin >> n;
    vector<i64> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    __int128 sum = 0;
    __int128 sqsum = 0;

    for (int i = 0; i < n; ++i) {
        sum += a[i];
        sqsum += (__int128)a[i] * a[i];
    }

    __int128 sumSq = sum * sum;
    __int128 num = sumSq - sqsum;
    __int128 den = (__int128)n * (n - 1);

    __int128 g = gcd(num, den);
    num /= g;
    den /= g;

    // Now num and den are coprime. Calculate num * inv(den) mod 1e9+7
    mi numerator = num % MOD;
    mi denominator = den % MOD;

    cout << int(numerator * inv(denominator)) << '\n';
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
