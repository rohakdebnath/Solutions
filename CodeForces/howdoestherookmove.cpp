#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

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
void solve()
{
    int N, K; cin >> N >> K;
    rep(i, 0, K){
        int r, c; cin >> r >> c;
        if (r == c){
            N--;
        } else {
            N -= 2;
        }
    }
    vector<mi> dp (N + 1); //dp[i] no. of configurations when i rows are left to be filled. dp[i] = dp[i - 1] + dp[i - 2] * 2 * (i - 1). We should fix the operation lets say from the last row to the first, then count the ways to fill the board. This is because 
    // otherwise there will be overcounting. If we fix the row of the column in our head, then there will be no overcounting. Lets fix the rows in our head. We take a row and see how many ways to pick colums, if we picking r = c, there is only one way so we need to build dp[i - 1] after picking r = c. Other is r != c, in which case we have (i - 1) choices but the piece can be b/w so * 2. we will need to build dp[i - 2] after that hence the formula
    dp[0] = dp[1] = 1;
    rep(i, 2, N + 1){
        dp[i] = dp[i - 1] + 2 * (i - 1) * dp[i - 2];
    }
    cout << int(dp[N]) << '\n';
}

int main()
{
    UNSYNC
    precompute_factorials();
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
