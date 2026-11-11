#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int MOD = 1e9 + 7;  // Change as required
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
    vector<string> s (2);
    vector<int> type (n);
    cin >> s[0] >> s[1];

    mi ans = 1;
    int j = 0;
    if (s[0][0] == s[1][0]) ans *= 3, j += 1, type[0] = 0;
    else ans *= 6, j += 2, type[1] = 1;
    while (j < n) {
        if (s[0][j] == s[1][j]) {
            if (type[j - 1] == 0) {
                ans *= 2;
            }
            j += 1;
        } else {
            if (type[j - 1] == 0) {
                ans *= 2;
                type[j + 1] = 1;
            } else {
                ans *= 3;
                type[j + 1] = 1;
            }
            j += 2;
        }
    }
    cout << int(ans) << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
