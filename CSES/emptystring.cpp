#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int MOD = 1e9 + 7;  // Change as required
const int MAX = 500; // Maximum value of n required

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
    string s; cin >> s;
    int n = s.size();
    vector<vector<mi>> dp (n + 1, vector<mi> (n + 1)); //dp[i][j] = ways to empty substring i..j
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			dp[i][j] = 1;
		}
	}
    vector<vector<mi>> bins(501, vector<mi>(501));
	for (int i = 0; i <= 500; i++) {
		for (int j = 0; j <= 500; j++) {
			bins[i][j] = nCr(i, j);
		}
	}
    for (int i = n - 1; i >= 0; --i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = i + 1; k <= j; ++k) {
                if (s[i] == s[k]) dp[i][j] += dp[i + 1][k - 1] * dp[k + 1][j] * bins[(j - i + 1) / 2][(k - i + 1) / 2];
            }
        }
    }
    cout << int(dp[0][n - 1]) << '\n';
}

signed main()
{
    precompute_factorials();
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
