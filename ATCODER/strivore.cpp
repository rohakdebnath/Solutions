#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)

#define MX 2000000
const long long MOD = 1e9 + 7;

long long fact[2000001];
long long inv[2000001];

void factorial(){
    fact[0] = 1;
    rep(i, 1, MX + 1){
        fact[i] = fact[i - 1] * i % MOD;
    }
    return;
}
long long binexp(long long base, long long pow){
    if (pow < 0) return 0;
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

i64 ncr(i64 n, i64 r){
    if (n < r) return 0;
    return fact[n] * inv[n - r] % MOD * inv[r] % MOD;
}
int main()
{
    UNSYNC
    factorial();
    inverse();
    i64 K; cin >> K;
    string S; cin >> S;
    i64 sz = S.size() + K;
    i64 ans = 0;
    rep(i, 0, sz){
        i64 before = i - S.size() + 1;
        i64 after = sz - i - 1;
        ans = (ans + binexp(25, before) * binexp(26, after) % MOD * ncr(sz - after - 1, S.size() - 1) % MOD) % MOD;
    }
    cout << ans << '\n';
    return 0;
}
