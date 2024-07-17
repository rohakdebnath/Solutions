#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

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
int main()
{
    UNSYNC
    factorial();
    inverse();
    int n, m; cin >> n >> m;
    cout << fact[n + m - 1] * inv[n - 1] % MOD * inv[m] % MOD << '\n';
    return 0;
}
