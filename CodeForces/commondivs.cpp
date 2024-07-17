#include <bits/stdc++.h>
 
using namespace std;
using i64 = long long;
 
#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)
 
const i64 MOD = 1e9 + 7;
i64 exp(i64 base, i64 pow){
    i64 res = 1;
    while (pow){
        if (pow & 1) res = res * base % MOD;
        base = base * base % MOD;
        pow /= 2;
    }
    return res;
}
int main()
{
    UNSYNC
    i64 N; cin >> N;
    map<i64, i64> primes;
    rep(i, 0, N){
        i64 x, p; cin >> x >> p;
        primes[x] = p;
    }
    i64 num = 1;
    i64 numphi = 1;
    i64 sum = 1;
    i64 prod = 1;

    for (auto [u, v]: primes){
        num = num * (v + 1) % MOD;
        sum = (sum * (exp(u, v + 1) - 1 + MOD) % MOD) * exp(u - 1, MOD - 2) % MOD;
        prod = exp(prod, v + 1) * exp(exp(u, v * (v + 1) / 2), numphi) % MOD; // Prod[i] = Prod[i - 1]^(Ki + 1)*(x^(KiC2))^numphi; here numphi is the product of (1 + K)s before this i, n^(number of products is impossible for me to implement)
        numphi = numphi * (v + 1) % (MOD - 1);
        cout << num << ' ' << sum << ' ' << prod << '\n';
        return 0;
    }
}
