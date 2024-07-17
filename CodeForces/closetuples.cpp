#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

#define MX 1000000
const long long MOD = 1e9 + 7;

long long fact[1000001];
long long inv[1000001];

void factorial(){
    fact[0] = 1;
    rep(i, 1, MX + 1){
        fact[i] = fact[i - 1] * i % MOD;
    }
    return;
}
long long binexp(long long base, long long pow){
    long long res = 1;
    base %= MOD;
    while (pow){
        if (pow & 1) res = res * base % MOD;
        pow /= 2;
        base = base * base % MOD;
    }
    return res;
}
void inverse(){
    inv[MX] = binexp(fact[MX], MOD - 2);
    per(i, MX, 1) inv[i - 1] = inv[i] * i % MOD;
}

int ncr(int n, int r){
    if (n < r) return 0;
    return fact[n] * inv[n - r] % MOD * inv[r] % MOD;
}

void solve()
{
    int n, m, k; cin >> n >> m >> k;
    vector<int> A (n); rep(i, 0, n) cin >> A[i];
    sort(all(A));
    int ans = 0;
    int j = 0;
    rep(i, 0, n){
        while (A[j] - A[i] <= k and j < n) ++j;
        ans = (ans + ncr(j - i - 1, m - 1)) % MOD;
    }
    cout << ans << '\n';
}

int main()
{
    UNSYNC
    factorial();
    inverse();
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
