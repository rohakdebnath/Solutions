#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

#define MX 1000000
const long long MOD = 998244353;

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
    if (r > n) return 0;
    return fact[n] * inv[n - r] % MOD * inv[r] % MOD;
}
void solve()
{
    int N; cin >> N;
    rep(i, 1, N + 1){
        if (i == 1 or i > (N + 1)/2){
            cout << "0 ";
            continue;
        }
        int sz = 2*(i - 1);
        cout << ncr(N - i - 1, i - 2) * fact[N - sz] % MOD * fact[sz] % MOD * (N - sz + 1) % MOD << ' ';
    }
    cout << '\n';
}

int main()
{
    factorial();
    inverse();
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
