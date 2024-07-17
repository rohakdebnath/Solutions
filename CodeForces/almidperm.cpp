#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)

#define MX 1000000
const i64 MOD = 1e9 + 7;

i64 fact[1000001];
i64 inv[1000001];
i64 der[1000001];

void factorial(){
    fact[0] = 1;
    rep(i, 1, MX + 1){
        fact[i] = fact[i - 1] * i % MOD;
    }
    return;
}
i64 binexp(i64 base, i64 pow){
    i64 res = 1;
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

void derange(){
    der[0] = 1, der[1] = 0;
    rep(i, 2, MX + 1){
        der[i] = (i - 1) * (der[i - 1] + der[i - 2]) % MOD;
    }
}

i64 ncr(i64 n, i64 r){
    return (fact[n] * inv[n - r]) % MOD * inv[r] % MOD;
}

int main()
{
    UNSYNC
    factorial();
    inverse();
    derange();
    i64 n, k; cin >> n >> k;
    i64 ans = 0;
    rep(i, 0, k + 1){
        ans = (ans + ncr(n, i) * der[i] % MOD) % MOD;
    }
    cout << ans << '\n';
    return 0;
}
