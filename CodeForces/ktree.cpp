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

void solve() {
    int n, k, d;
    cin >> n >> k >> d;
    vector<vector<mi>> dp(n + 1, vector<mi> (2)); //dp[i][j] number of ways to sum to n with using an element >= d atleast once or not
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int w = 1; w <= k; ++w) {
            if (i + w > n) break;
            dp[i + w][w >= d] += dp[i][0];
            dp[i + w][1] += dp[i][1];
        }
    }
    cout << int(dp[n][1]) << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
