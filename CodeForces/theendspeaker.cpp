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

const i64 inf = 1e9;
void solve() {
    i64 n, m; cin >> n >> m;
    vector<i64> a (n); for (i64 i = 0; i < n; ++i) cin >> a[i];
    vector<i64> b (m); for (i64 i = 0; i < m; ++i) cin >> b[i];

    vector<i64> p (n + 1); partial_sum(a.begin(), a.end(), p.begin() + 1);
    vector dp (n + 1, vector<pair<int, mi>> (m + 1, {inf, 0})); //dp[i][j] = min cost, ways to remove prefix i when your value of k is 'j'
    dp[0][0] = {0, 1}; // one thing to note in dp is that it is increasing for a fixed k, 
    for (i64 k = 0; k < m; ++k) {
        mi ways = 0;
        for (i64 i = 1, j = 0, l = 0; i <= n; ++i) { 
            while (p[i] - p[j] > b[k]) {
                ways -= dp[j++][k + 1].second;
            }
            if (l < j) { 
                l = j;
                ways = 0;
            }
            while (l < i and dp[l][k + 1].first == dp[j][k + 1].first) {
                ways += dp[l++][k + 1].second;
            }
            if (j < i) {
                int x = dp[j][k + 1].first + m - 1 - k;
                dp[i][k + 1] = dp[i][k];
                if (x < dp[i][k + 1].first) {
                    dp[i][k + 1] = {x, ways};
                } else if (x == dp[i][k + 1].first) {
                    dp[i][k + 1].second += ways;
                }
            }
        }
    }
    if (dp[n][m].first == inf) cout << "-1\n";
    else {
        cout << dp[n][m].first << ' ' << int(dp[n][m].second) << '\n';
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    i64 T; cin >> T;
    while(T--) solve();
    return 0;
}

//lore:
//since all values from j to i - 1 are valid starting removal position from {position} to i using m - 1 - k cost, all of them can be used as the starting position for a removal
//however the cost to reach destination (dp[i][k]) will 100% increase if you start a removal from a position whose cost is higher than dp[j][k] (obvious lol since the cost of all such jumps are fixed at m - 1 - k)
//therefore to count the number of ways of cheapest removal, we should consider only the places where the cost {till that position} is the same as the cost of dp[j][k]
//since the dp is increasing, such values will only be found in the first few spots after dp[j][k] and also enables us to use 2P to continue the increment of l when we move to i + 1 from i
