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
    int N; cin >> N;
    vector<int> A (N);
    for (int i = 0; i < N; ++i) {
        int x; cin >> x;
        A[i] = x & 1;
    }
    mi ans = 0;
    vector<mi> bm (4); //bitmask for simulation of two digits
    vector<int> c (2);
    for (int i = 0; i < N; ++i) {
        auto t = bm;
        for (int f = 0; f < 2; ++f) {
            int s = f ^ A[i];
            bm[s | A[i] << 1] += t[f | s << 1]; //extension of subsequences which can be safely extended 
            ans += t[f | s << 1];
        }
        bm[1 | A[i] << 1] += c[1]; // this is the creation of new subsequences starting with 1 or 0 and the second letter being A[i]
        bm[0 | A[i] << 1] += c[0];
        ++c[A[i]];
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
