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
    i64 n, a, b; cin >> n >> a >> b;
    vector<char> d (n); for (i64 i = 0; i < n; ++i) cin >> d[i];

    auto check = [&] (i64 l, i64 r) -> mi{
        map<pair<i64, string>, mi> dp; 
        auto dfs = [&] (auto&& self, i64 i, string s = "") -> i64 {
            if (i == r) {
                if (s.size() == 0) return 0;
                return (stoll(s) <= b and stoll(s) >= a);
            }
            if (int(dp[{i, s}])) return int(dp[{i, s}]);
            i64 way = self(self, i + 1, s + d[i]) + self(self, i + 1, d[i] + s) + self(self, i + 1, s);
            dp[{i, s}] = int(way);
            return way;
        };
        return dfs(dfs, l, "");
    };
    i64 q; cin >> q;
    for (i64 _ = 0; _ < q; ++_) {
        i64 l, r; cin >> l >> r;
        --l;
        cout << int(check(l, r)) << '\n';
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
