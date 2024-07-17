#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

const int MOD = 1e9 + 7;
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
    assert(p >= 0);
    return p == 0 ? 1 : pow(a * a, p / 2) * (p & 1 ? a : 1);
}
mi inv(mi a) {
    assert(a.v != 0);
    return pow(a, MOD - 2);
}
mi operator/(mi a, mi b) { return a * inv(b); }

void solve()
{
    int M, N; cin >> M >> N;
    vector<int> S (M); rep(i, 0, M) cin >> S[i];
    vector<int> L (M); rep(i, 0, M) cin >> L[i];
    vector<vector<mi>> dp (N + 1, vector<mi> (M)); // dp[i][j] no. of ways to travel at the end of the ith day and end at j
    dp[0][0] = 1; 
    rep(i, 1, N + 1){
        rep(j, 0, M){
            rep(k, 0, M){
                dp[i][j] += dp[i - 1][k] * ((S[k] + L[k]) * (S[j] + L[j]) - L[k] * L[j]);
            }
        }
    }
    cout << int(accumulate(all(dp[N]), mi(0))) << '\n';
}

int main()
{
    UNSYNC
    int T = 1;
    while(T--) solve();
    return 0;
}
