#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int mod = 1e9 + 7;
const int maxn = 1e6;

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

vector<vector<int>> fact(maxn + 1);

void solve() {
    i64 n; cin >> n;
    vector<i64> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    
    vector<mi> dp(n + 1); //dp[i] = number of good subsequences ending with length i
    //a number a[i] can end at all f, such that f is a factor of a[i]
    dp[0] = 1;
    
    for(auto x : a){
        for(auto it = fact[x].rbegin(); it != fact[x].rend(); ++it){
            int f = *it;
            if(f <= n){
                dp[f] += dp[f - 1];
            }
        }
    }
    
    mi ans = 0;
    for(int f = 1; f <= n; ++f){
        ans += dp[f];
    }
    cout << int(ans) << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    for(int f = 1; f <= maxn; ++f){
        for(int m = f; m <= maxn; m += f){
            fact[m].push_back(f);
        }
    }
    solve();
    return 0;
}
